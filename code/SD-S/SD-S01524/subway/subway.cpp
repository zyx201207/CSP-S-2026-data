#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int w[500005];
vector <pii > st;
vector <int> a[500005],b[500005];
int dis[500005];
bool vis[500005];
priority_queue <pii,vector <pii >,greater<pii > > pq;
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i],w=b[u][i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
		vis[u]=true;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		st.clear();
		for(int j=1;j<=k;j++){
			int id,t;cin>>id>>t;
			for(int x=0;x<st.size();x++){
				int u=st[x].first,v=id,w=st[x].second+t;
				a[u].push_back(v),a[v].push_back(u);
				b[u].push_back(w),b[v].push_back(w);
			}
			st.push_back({id,t});
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		dij(u);
		cout<<dis[v]+w[u]+w[v]<<'\n';
	}
	return 0;
}
