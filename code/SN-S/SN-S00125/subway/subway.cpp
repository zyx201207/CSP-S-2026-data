#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
int c,n,m,d,q,id;
int w[maxm];
int k[maxn];
vector<int> a[maxn],t[maxn];
vector<pair<int,int> > e[maxm];
int dis[20*maxm];
bool vis[20*maxm];
void dij(int x){
	priority_queue<pair<int,int> > pq;
	for(int i=1;i<=m*2;i++) dis[i]=1e18, vis[i]=0;
	pq.push({0,x});
	dis[x]=0;
	int cnt=0;
	while(!pq.empty()&&cnt<id){
		int u=pq.top().second;
//		if(vis[u]==1){
//			pq.pop();
//			continue;
//		}
		vis[u]=1;
		cnt++;
		pq.pop();
		for(auto cur:e[u]){
			int v=cur.first;
			int w=cur.second;
			if(!vis[v]){
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					pq.push({-dis[v],v});
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	id=m;
	for(int i=1;i<=m;i++) 
		cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		int l=id;
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j],
			e[a[i][j]].push_back({++id,t[i][j]}),
			e[id].push_back({a[i][j],t[i][j]});
		for(int j=l+2;j<=id;j++){
			e[j-1].push_back({j,0});
			e[j].push_back({j-1,0});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		dij(x);
		int ans1=dis[y];
		dij(y);
		int ans2=dis[x];
//		cout<<x;
		cout<<ans+min(ans1,ans2);
//		for(int i=1;i<=id;i++){
//			cout<<i<<" "<<dis[i]<<"\n";
//		}
		cout<<"\n";
//		return 0;
	}
	return 0;
}
