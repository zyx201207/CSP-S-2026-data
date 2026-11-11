#include<bits/stdc++.h>//
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
inline ll read(){
	ll x = 0,f = 1;
	char c = getchar();
	while(('0' > c || c > '9') && c != '-')c = getchar();
	if(c == '-')f = -1,c = getchar();
	while('0' <= c && c <= '9')x = x * 10 + c - 48,c = getchar();
	return x * f;
}
#define N 1000005
ll c,_,n,k,fa[N],vis[N],dis[N],vis2[N],cps;
vector<ll> ed[N];
void dfs(ll u,ll f){
	fa[u] = f;
	for(auto v : ed[u]){
		if(v == f)continue;
		dfs(v,u);
	}
}
void dfs2(ll u,ll f){
	vis2[u] = 1;
	for(auto v : ed[u]){
		if(v == f || !vis[v])continue;
		dfs2(v,u);
	}
}
void dfs3(ll u,ll f,ll ds){
	dis[u] = min(dis[u],ds);
	for(auto v : ed[u]){
		if(v == f)continue;
		dfs3(v,u,ds + 1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),_ = read();
	while(_--){
		n = read(),k = read();
		rep(i,1,n)ed[i].clear();
		rep(i,1,n - 1){
			ll U,V;
			U = read(),V = read();
			ed[U].push_back(V);
			ed[V].push_back(U);
		}
		dfs(1,0);
		if(c <= 3){
			ll ans = 1e18;
			rep(i,0,(1 << n) - 1){
//				cout << i << endl;
				ll chs = 0;
				rep(j,1,n){
					dis[j] = 1e9;
					vis2[j] = vis[j] = 0;
					if((1 << (j - 1)) & i)vis[j] = 1,++chs;
				}
//				cout << chs << endl;
				if(chs != k)continue;
				cps = 0;
				rep(j,1,n){
					if(vis[j] && !vis2[j]){
						++cps;
						dfs2(j,0);
					}
				}
				if(cps > 2)continue;
//				cout << "surv" << endl;
				rep(j,1,n){
					if(vis[j]){
						dfs3(j,0,0);
					}
				}
				ll res = 0;
				rep(j,1,n)res = max(res,dis[j]); 
				ans = min(ans,res);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
