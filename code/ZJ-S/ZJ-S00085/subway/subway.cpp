#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6e5+5;
ll c,n,m,d,q_,w[N],vis[505][505];
vector<pair<ll,ll> > mp[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q_);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	memset(vis,-1,sizeof vis);
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		
		for(ll j=1;j<=k;j++){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			mp[i].push_back({a+n,t});
			mp[a+n].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++)vis[i][i]=0;
	for(ll i=1;i<=n;i++){
		for(ll _1=0;_1<mp[i].size();_1++){
			pair<ll,ll> j=mp[i][_1];
			for(ll _2=0;_2<mp[j.first].size();_2++){
				pair<ll,ll> h=mp[j.first][_2];
				if(vis[i][h.first]==-1)vis[i][h.first]=j.second+h.second;
				else vis[i][h.first]=min(j.second+h.second,vis[i][h.first]);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll h=1;h<=n;h++){
				if(vis[i][j]!=-1&&vis[j][h]!=-1){
					if(vis[i][h]==-1)vis[i][h]=vis[i][j]+vis[j][h];
					else vis[i][h]=min(vis[i][h],vis[i][j]+vis[j][h]);
				}
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n+m;j++)op[j]=-1;
//		dij(i);
//	}
	while(q_--){
		ll x,y,ans=LONG_LONG_MAX;
		scanf("%lld%lld",&x,&y);
		for(ll h=0;h<mp[x+n].size();h++){
			pair<ll,ll> i=mp[x+n][h];
			for(ll _=0;_<mp[y+n].size();_++){
				pair<ll,ll> j=mp[y+n][_];
				ans=min(ans,vis[i.first][j.first]+i.second+j.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
