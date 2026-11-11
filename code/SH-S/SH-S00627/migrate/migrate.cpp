#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll c,t,n,d,x[N],dis[5010][5010],cnt[5010][5010];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11 || c==12)
		while(t--) {
			cin>>n>>d;
			for(ll i=1; i<=n; ++i) cin>>x[i];
			if(n==1) cout<<"0\n";
			else {
				d/=x[2]-x[1];
				if(d>1) cout<<max(0ll,n-d*2+1)<<"\n";
				else cout<<"0\n";
			}
		}
	else
		while(t--) {
			cin>>n>>d;
			for(ll i=1; i<=n; ++i) cin>>x[i];
			for(ll i=1; i<=n; ++i) for(ll j=1; j<=n; ++j) dis[i][j]=1e9,cnt[i][j]=0;
			for(ll i=1; i<n; ++i) for(ll j=i+1; j<=n; ++j) if(x[j]-x[i]<=d) dis[i][j]=1,cnt[i][j]=1;
			for(ll k=1; k<=n; ++k)
				for(ll i=1; i<=n; ++i)
					for(ll j=1; j<=n; ++j)
						if(dis[i][j]>dis[i][k]+dis[k][j]) {
							dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
							if(cnt[i][j]>2) cnt[i][j]=3;
						} else if(dis[i][j]==dis[i][k]+dis[k][j]) {
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
							if(cnt[i][j]>2) cnt[i][j]=3;
						}
			ll ans=0;
			for(ll i=1; i<n; ++i) for(ll j=i+1; j<=n; ++j) if(cnt[i][j]==2) ++ans;
			cout<<ans<<"\n";
		}
	return 0;
}
