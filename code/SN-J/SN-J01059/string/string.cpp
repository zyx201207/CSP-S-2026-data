#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
	long long len;
	char c;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c; 
	}
	long long ans=0; 
	int i=1,j=n-i+1;
	while(i<=j){
		if(a[i].c!=a[j].c){
			ans+=min(a[i].len,a[j].len);
		}
		if(a[i].len<a[j].len){
			a[j].len-=a[i].len;
			i++;
		}else if(a[i].len>a[j].len){
			a[i].len-=a[j].len;
			j--;
		}else{
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}
