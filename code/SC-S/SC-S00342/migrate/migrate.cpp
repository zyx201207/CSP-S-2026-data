#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
ll t,n,d;
ll ans,a[N],js[N],dp[N];
ll ask(ll x){
	int r=n,l=0;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(x-a[mid]<=d)r=mid;
		else l=mid;
	}
	return r;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;cin>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(ll i=1;i<=n;i++)js[i]=0,dp[i]=0;
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=2;i<=n;i++){
			int t=ask(a[i]);
			if(i>2&&a[i-1]-a[t-1]>d)
			dp[i]=dp[t],ans+=dp[i];
//			cout<<t<<' '<<dp[i]<<' '<<ans<<'\n';
			if(i>3){
//				cout<<i<<":\n";
//				if(a[i]-a[i-3]>d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-2]<=d){
				int t=ask(a[i]);
				if(t+2<=i){
					int u=ask(a[t+2]);
					int l=ask(a[t]);
					ans+=u-l;dp[i]+=u-l;
//					cout<<l<<' '<<u<<'\n';
					if(l!=u){
//						cout<<i<<":\n";
						int last=l;//cout<<u<<' ';
						while(last!=1){
							t=ask(a[last+1]);
							int tt=ask(a[last]);
							if(tt==t)break;
							ans+=t-tt;dp[i]+=t-tt;
							last=tt;
//							cout<<t<<','<<tt<<' ';
						}
//						cout<<'\n';
					}
				}
			}
		}
	cout<<ans<<'\n';
	}
	return 0;
}
/*
1 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/