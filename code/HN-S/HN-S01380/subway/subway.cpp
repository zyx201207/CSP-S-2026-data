#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+500;
struct ovo{
	int v,w;
};
int c,n,m,d,q,w[M],vis[M],dis[M];
vector<ovo>vec[M+500];
vector<int>ans[M];
void solu(int x,int y){
	memset(vis,0,sizeof(vis));
	memset(dis,63,sizeof(dis));
	queue<int>q;
	q.push(x);vis[x]=1;dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].v,w=vec[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	cout<<dis[y]+w[x]+w[y]<<'\n';
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			vec[m+i].push_back({v,w});
			vec[v].push_back({m+i,w});
		}
		
	}	for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			solu(x,y);
		}
	return 0;
} 
