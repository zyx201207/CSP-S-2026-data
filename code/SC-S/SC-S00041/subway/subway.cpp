#include<bits/stdc++.h>
using namespace std;
//思路建图，但是对于每个点，为其增加编号，表示哪些地铁线经过它
//使用spfa求路径，对于编号不同的点，走过去需要加上额外时间
int c,n,m,d,q; 
int w[(int)5e5+10];
vector<vector<pair<int,int> > >adj;
//adj[i][j].fi是i站厅到的线路，se是时间 
vector<vector<int> >e;//每条路线到达的站点 
long long spfa(int x,int y){
	queue<pair<int,int> > q;//fi是i点是由哪条路线来的 
	q.push(make_pair(-1,x));
	
	bool vis[(int)5e5+10]={0};
	long long dis[(int)5e5+10];
	
	for(int i=1;i<=m;i++)dis[i]=0x3f3f3f3f;
	dis[x]=0;
	
	while(!q.empty()){
		pair<int,int> u=q.front();
		if(vis[u.second]||u.second==y)continue;
		vis[u.second]=1;
		q.pop();
		
		//u.first是点由哪条线路走过来,u.second是点 
		
		for(int i=0;i<adj[u.second].size();i++){//adj的第一是点，fi是线路,se是时间 
			int v=adj[u.second][i].first;
			for(int j=0;j<e[v].size();j++){
				
				int hf=0;
				if(v==u.first){
					hf=0;
				}else{
					for(int o=0;o<adj[u.second].size();o++){
						if(adj[u.second][o].first==u.first){
							hf=adj[u.second][o].second+adj[u.second][i].second;
							break;
						}
					}
				}
				if(hf+dis[u.second]<dis[e[v][j]]){
					dis[e[v][j]]=hf;
				}
				if(!vis[e[v][j]])q.push(make_pair(v,e[v][j]));
				
			}
		}
	}
	
	return dis[y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	
	cin>>c>>n>>m>>d>>q;
	adj.resize(m+10);
	e.resize(n+10);
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,b;j<=k;j++){
			cin>>a>>b;
			adj[a].push_back(make_pair(i,b));
			e[i].push_back(a);
		}
	}
	
	freopen("subway.out","w",stdout);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<spfa(x,y)+w[x]+w[y]<<'\n';
	}
	
	
	
	

	return 0;
}
