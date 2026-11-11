#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	long long c;
	char a;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].a;
	}
	for(int i=1;i<=n;i++){
		b[i].c=a[n-i+1].c;
		b[i].a=a[n-i+1].a;
	}
	int i=1,j=1;
	while(i<=n&&j<=n){
		if(a[i].a!=b[j].a){
			ans+=min(a[i].c,b[j].c);
		}
		if(a[i].c>b[j].c){
			a[i].c=a[i].c-b[j].c;
			j++;
		}
		else if(a[i].c<b[j].c){
			b[j].c=b[j].c-a[i].c;
			i++;
		}
		else{
			i++;
			j++;
		}
	}
	cout<<ans/2;
	return 0;
} 

