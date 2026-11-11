#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ls(x) (x<<1)
#define rs(x) (x<<1 | 1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
priority_queue<pii, vector<pii>, greater<pii> > q;
const int N=5e5+10;
ll dis[N*20];
ll w[N];
const int INF=4e18;
int _,n,m,d,qq,tot;
vector<pii> g[N];
void dijk(int x){
	while(q.size()) q.pop();
	q.push(mp(0,x));
	for(int i=1; i<=2*m+tot; i++) dis[i]=INF;
	dis[x]=0;
	while(q.size()){
		pii t=q.top();
		q.pop();
		int d=t.fi;
		int u=t.se;
		if(dis[u]!=d) continue;
		
		for(auto tt:g[u]){
			int v=tt.fi;
			int w=tt.se;
			if(dis[v]>dis[u]+w){
				
				dis[v]=dis[u]+w;
				//cout<<dis[v]<<" "<<v<<"\n";
				q.push(mp(dis[v],v));
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>n>>m>>d>>qq;
	for(int i=1; i<=m; i++){
		cin>>w[i];
		g[i].pb(mp(m+i,w[i]));
		g[m+i].pb(mp(i,w[i]));
	}
	int lstx=0;
	for(int i=1,k; i<=n; i++){
		cin>>k;
		for(int j=1,x,y; j<=k; j++){
			
			cin>>x>>y;
			++tot;
			g[x+m].pb(mp(2*m+tot,y));
			g[2*m+tot].pb(mp(x+m,y));
			if(j>=2){
				g[2*m+tot].pb(mp(lstx,0));
				g[lstx].pb(mp(2*m+tot,0));
			}
			lstx=2*m+tot;
		}
	}
	for(int i=1,u,v; i<=qq; i++){
		cin>>u>>v;
		dijk(u);
		cout<<dis[v]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

