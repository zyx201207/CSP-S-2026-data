#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],x,y,dis[500005],ans;
int a[505][10005],t[505][10005],k[505];
struct node{
	int to,val;
};
vector<node> g[500005];
bool flag;
queue<int> pq;
int bfs(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	pq.push(x);
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			if(dis[v]>dis[u]+g[u][i].val){
				dis[v]=dis[u]+g[u][i].val;
				pq.push(v);
			}
		}
	}
	return dis[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)flag=1;
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=k[i];j++){
				int dtz=a[i][j],last_dtz=a[i][j-1];
				int bq=t[i][j]+t[i][j-1];
				g[dtz].push_back({last_dtz,bq});
				g[last_dtz].push_back({dtz,bq});
			}
		}
		while(q--){
			cin>>x>>y;
			ans=bfs(x,y);
			cout<<ans+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
