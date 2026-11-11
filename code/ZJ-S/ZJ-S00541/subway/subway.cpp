#include<bits/stdc++.h>
#define int long long
#define pa pair<int,pair<int,int> > 
using namespace std;
const int N=505,M=5e5+5,INF=1e18+10;
int c,n,m,d,Q,x,y,w[M],k[N],bis[M];
vector<vector<int> > dis;
vector<int> vec[M],dx[M];
bool vis[M];
struct node{
	int a,t;
	node(){}
	node(int na,int nb){
		a=na,t=nb;
	}
};
map<int,int> ap[N];
queue<pa> q;
void fdd(){
	while(!q.empty()){
		pa now=q.front();
		q.pop();
		int d=now.first;
		int u=now.second.first;
//		cout<<u<<".\n";
		int xl=now.second.second;
//		cout<<d<<" "<<dis[u]<<"\n";
		if(d>dis[u][xl])continue;
//		cout<<"#1\n";
		for(int i=0;i<(int)dx[u].size();i++){
			int ul=dx[u][i];
			int w=1;
			if(ul!=xl){
				w+=ap[xl][u]+ap[ul][u];
			}
			for(int v:vec[u]){
//				cout<<"#2 ";
//				cout<<u<<" "<<v<<":\n";
//				cout<<"  ";
//				for(int k=0;k<(int)dx[u].size();k++){
//					cout<<dx[u][k]<<" ";
//				}cout<<"\n";
//				cout<<"  ";
//				for(int k=0;k<(int)dx[v].size();k++){
//					cout<<dx[v][k]<<" ";
//				}cout<<"\n";
				int dl=lower_bound(dx[v].begin(),dx[v].end(),ul)-dx[v].begin();
				if(dl>=dx[v].size())continue;
				dl=dx[v][dl];
//				cout<<"#"<<ul<<","<<dl<<"\n";
//				cout<<"so:"<<w<<"\n";
				if(dl!=ul)continue;
//				cout<<"w="<<w<<"\n";
//				cout<<dis[v]<<"-"<<dis[u]+w<<"\n";
				if(dis[v][dl]>dis[u][xl]+w){
					dis[v][dl]=dis[u][xl]+w;
					q.push({dis[v][dl],{v,dl}});
				}
			}
		}
	}
	return ;
}
void dij(int sx){
	if(dx[sx].empty())return ;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
	for(int i=0;i<(int)dx[sx].size();i++){
		dis[sx][dx[sx][i]]=ap[dx[sx][i]][sx];
		q.push({dis[sx][dx[sx][i]],{sx,dx[sx][i]}});
	}
	fdd();
	return ;
}
void bfs(int sx){
	for(int i=1;i<=m;i++)bis[i]=INF;
	bis[sx]=0;
	queue<int> qq;
	qq.push(sx);
	while(!qq.empty()){
		int u=qq.front();
		qq.pop();
		for(int v:vec[u]){
			if(bis[v]>bis[u]+1){
				bis[v]=bis[u]+1;
				qq.push(v);
			}
		}
	}return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	dis.resize(m+5,vector<int>(n+5,0));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		int last=0;
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			ap[i][a]=t;
			dx[a].push_back(i);
			if(j>1)vec[last].push_back(a);
			last=a;
		}
	}
	for(int i=1;i<=m;i++){
		sort(dx[i].begin(),dx[i].end());
	}
	while(Q--){
		cin>>x>>y;
		dij(x);
		bfs(x);
		int res=INF;
		for(int i=0;i<dx[y].size();i++){
			if(dis[y][dx[y][i]]<INF)res=min(res,dis[y][dx[y][i]]+ap[dx[y][i]][y]);
		}
		res+=w[x]+w[y]-bis[y];
		cout<<res<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
