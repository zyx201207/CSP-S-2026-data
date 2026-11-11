#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001],pre[500001]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	long long r=1;
	long long ans=0;//¿ÅÊý 
	for(long long l=1;l<=n;l++){
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m&&r<=n){
//			cout<<l<<" "<<r<<" "<<a[r]*(r-l+1)-(pre[r]-pre[l-1])<<endl;
			++r;
		}
		--r;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
