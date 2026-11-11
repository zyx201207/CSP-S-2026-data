#include<bits/stdc++.h>
using namespace std;
struct node{
	int len;
	char c;
};
long long n,ans;
node a[200005];
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;		
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			ans+=min(a[l].len,a[r].len);
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
