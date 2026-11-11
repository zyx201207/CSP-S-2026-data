#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define int ll
#define PII pair<int,int>
#define all(v) v.begin(),v.end()
using namespace std;
const int N=550,M=5e5+10;
const ll inf=1e18;
int a[M][40],t[M][40],cnt[M];
int T=1,c,n,m,d,q,w[M],u,v,k;
vector<PII>g[N];
ll dis[N][N],ww[N][N];
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII>>pq;
void dijk(int s){
	fill(vis+1,vis+n+1,0);
	fill(dis[s]+1,dis[s]+n+1,inf);
	dis[s][s]=0;
	pq.emplace(0,s);
	while(!pq.empty()){
		auto TOP=pq.top();pq.pop();
		int u=TOP.second,d=TOP.first;
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[s][v]>d+w){
				dis[s][v]=d+w;
				pq.emplace(d+w,v);
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u;
			a[u][++cnt[u]]=i;
			cin>>t[u][cnt[u]];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=a[i][j],v=a[i][k];
				if(ww[u][v])continue;
				ww[u][v]=ww[v][u]=t[i][j]+t[i][k];
				g[u].emplace_back(v,t[i][j]+t[i][k]);
				g[v].emplace_back(u,t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijk(i);
	}
//	cerr<<clock()-st<<"\n";
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ll ans=inf;
		for(int j=1;j<=cnt[u];j++){
			for(int k=1;k<=cnt[v];k++){
				int x=a[u][j],y=a[v][k];
				ans=min(ans,w[u]+w[v]+t[u][j]+t[v][k]+dis[x][y]);
			}
		}
//		dijk(v);
		cout<<ans<<"\n";
	}
	//终于啊！！！\approx 100pts!
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>T;
	while(T--)solve();
	sjh0626s code;
}