#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100500,inf = 1e18;
struct edge{
	ll to,nxt;
}e[maxn * 2];
ll tot,head[maxn];
void add(ll a,ll b){
	e[++tot] = (edge){b,head[a]};
	head[a] = tot;
}
ll n,k,cnt;
bool book[maxn];
void dfs(ll u,ll f){
	ll v,i;
	if(book[u] && !book[f]) cnt++;
	for(i = head[u];i;i = e[i].nxt){
		v = e[i].to;
		if(v == f) continue;
		dfs(v,u);
	}
}
ll maxdep;
void dfs2(ll u,ll f,ll d){
	ll v,i;
	maxdep = max(maxdep,d);
	for(i = head[u];i;i = e[i].nxt){
		v = e[i].to;
		if(v == f) continue;
		if(book[v]) dfs2(v,u,0);
		else dfs2(v,u,d + 1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll taskid,T;
	cin>>taskid>>T;
	ll i,j,u,v,mp;
	while(T--){
		cin>>n>>k;
		tot = 0;
		for(i = 1;i <= n;i++) head[i] = 0;
		for(i = 1;i < n;i++){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		ll ans = inf;
		for(mp = 0;mp < (1 << n);mp++){
			ll rt = 0,cnt1 = 0;
			for(i = 0;i < n;i++){
				if(mp & (1 << i)){
					book[i + 1] = 1;
					rt = i + 1;
					cnt1++;
				}else{
					book[i + 1] = 0;
				}
			}
			if(cnt1 != k) continue;
			cnt = 1;
			dfs(rt,rt);
			if(cnt > 2) continue;
			maxdep = 0;
			dfs2(rt,rt,0);
			ans = min(ans,maxdep);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
