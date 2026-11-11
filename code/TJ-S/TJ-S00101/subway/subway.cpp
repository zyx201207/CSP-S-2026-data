#include <bits/stdc++.h>
using namespace std;

const int M=5e5+5,N=505;
long long c,n,m,d,q,cnt[M],vis[M];
long long dis[N][N],w[M];
struct node{
	long long id;
	long long val;
	bool operator<(const node &o)const{
		return val>o.val;
	}
};
vector<node> st[M];
vector<node> e[M];	// every route

void dijkstra(int s){
	priority_queue<node> q;
	fill(dis[s]+1,dis[s]+n+1,1e18);
	fill(vis+1,vis+n+1,0);
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		long long u=q.top().id,val=q.top().val;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			long long v=e[u][i].id,w=e[u][i].val;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){//subway i
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int a,t;cin>>a>>t;
			st[a].push_back({i,t});// station a has metro i and takes t time
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			int fr=st[i][j].id,v1=st[i][j].val;
			for(int k=0;k<st[i].size();k++){
				if(j==k)continue;
				int to=st[i][k].id,v2=st[i][k].val;
				e[fr].push_back({to,v1+v2});
				e[to].push_back({fr,v1+v2});
			}
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	for(int i=1,xx,yy;i<=q;i++){
		cin>>xx>>yy;long long ans=1e18;
		for(int j=0;j<st[xx].size();j++){
			int fr=st[xx][j].id;
			long long v1=st[xx][j].val;
			for(int k=0;k<st[yy].size();k++){
				int to=st[yy][k].id;
				long long v2=st[yy][k].val;
				ans=min(ans,w[xx]+w[yy]+dis[fr][to]+v1+v2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

