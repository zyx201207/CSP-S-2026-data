#include<bits/stdc++.h>
using namespace std;
long long a[500010],d[500010],w[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;bool f=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}sort(a+1,a+n+1);s=a[2]-a[1];
	for(int i=2;i<=n;++i){
		d[i]=a[i]-a[i-1];
		w[i]=w[i-1]+a[i]-a[1];
		if(a[i]-a[i-1]!=s) f=1;
	}
	if(!f){
		if(1LL*(1LL*(1LL*((n*n)/2))*s)<=m){
			cout<<n;return 0;
		}
		for(long long i=n;i>1;--i){
			if(((i*(i-1))*1LL)*s*1LL<=m*2*1LL){
				cout<<min(n,i);return 0;
			}
		}
	}else{
		int maxn=0;int i=1;
			long long ans=0;
			for(int j=i+1;j<=n;++j){
				ans+=(j-i)*d[j]*1LL;
				if(ans>m){
					maxn=max(maxn,j-i);
					ans-=(w[j]-w[i-1]);++i;
				}
			}
		cout<<maxn;
	}//100pts no
	return 0;
} 
