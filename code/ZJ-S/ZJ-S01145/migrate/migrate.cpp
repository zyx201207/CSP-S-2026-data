#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
ll c,T,n,d,x[N],dis[N],cnt[N],vis[N];
vector<ll> g[N];
void bfs(ll s){
	queue<ll> q;
	q.push(s);
	for(ll i=1;i<=n;i++) vis[i]=0,dis[i]=LLONG_MAX,cnt[i]=0;
	dis[s]=0;
	cnt[s]=1;
	while(q.size()){
		ll now=q.front();
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(ll v : g[now]){
			if(dis[now]+1<dis[v]){
				dis[v]=dis[now]+1;
				cnt[v]=cnt[now];
				q.push(v);
			}else if(dis[now]+1==dis[v]){
				cnt[v]+=cnt[now];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}else{
					break;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			bfs(i);
			for(ll j=1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans/2<<endl;
		for(ll i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
