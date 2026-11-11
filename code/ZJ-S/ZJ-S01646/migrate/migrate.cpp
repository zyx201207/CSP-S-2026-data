#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=2e6+10;
int dis[N],a[N],tot[N],vis[N];
struct node{
	int v,w;
	bool operator>(const node &o) const {
		w>o.w;
	}
};
vector<node> g[N];
int n,d;
inline void dij(int x){
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
		tot[i]=0;
	}
	dis[x]=0;
	priority_queue<node,vector<node>,greater<node> > q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(node p : g[u]){
			int v=p.v,w=p.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				tot[v]=1;
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+w){
				tot[v]+=tot[u];
			}
		}
	}
}
signed main(){
	IOSO;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					g[i].push_back({j,1});
					g[j].push_back({i,1});
				} else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(tot[j]==2){
					ans++;
				}
//				cout<<i<<" "<<j<<" "<<dis[j]<<" "<<tot[j]<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		cout<<ans<<endl;
	}
	QwQ;
}