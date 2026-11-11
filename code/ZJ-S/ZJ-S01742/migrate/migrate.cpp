#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,x[2000005],ma[2000005],ways,minn=1e18;
void dfs(ll p,ll fin,ll step) {
	if(p==fin) {
		if(step==minn) {
			ways+=1;
		}
		else if(step<minn) {
			ways=1;
			minn=step;
		}
		return ;
	}
	for(ll i=p+1;i<=min(p+d,fin);i++) {
		if(ma[i]==1) {
			dfs(i,fin,step+1);
		}
	}
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		ll ans=0;
		memset(x,0,sizeof(x));
		memset(ma,0,sizeof(ma));
		cin>>n>>d;
		for(ll i=1;i<=n;i++) {
			cin>>x[i];
			ma[x[i]]=1;
		}
		for(ll i=2;i<=n;i++) {
			if(x[i]-x[i-1]>d) {
				n=i-1;//zuodewo xin liangliangde
				break;//wohaolenga!wodongsila!
			}
		}
		if(n<=3) {
			cout<<0<<endl;
			continue;
		}
		if(n>=10) {
			bool flag1=1;
			ll ax=x[2]-x[1];
			for(ll i=3;i<=n;i++) {
				if(x[i]-x[i-1]!=ax) flag1=0;
			}
			if(flag1) {
				
			}
			else {
				cout<<n*(n+1)/2<<endl;//
			}
			continue;
		}
		for(ll i=1;i<=n-3;i++) {
			for(ll j=i+3;j<=n;j++) {
				ways=0;
				minn=1e18;
				dfs(x[i],x[j],0);
				if(ways==2) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
