#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,int>
using namespace std;
ll n,D,x[2000006];

inline void solve(){
	cin>>n>>D;
	vector<vector<ll> >cnt(n+5),dis(n+5);
	for(int i=1;i<=n;i++){
		cnt[i].resize(n+5,0ll);
		dis[i].resize(n+5,n+5);
		cin>>x[i];
	}
	for(int d=1;d<=n;d++){
		for(int l=1;l+d-1<=n;l++){
			int r=l+d-1;
			if(x[r]-x[l]<=D){
				cnt[l][r]=1,dis[l][r]=1;
				continue;
			}
			for(int m=l+1;m<r;m++){
				if(x[m]-x[l]<=D){
					if(dis[l][r]>dis[m][r]+1) dis[l][r]=dis[m][r]+1,cnt[l][r]=cnt[m][r];
					else if(dis[l][r]==dis[m][r]+1) cnt[l][r]+=cnt[m][r];
				}
				else break;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
