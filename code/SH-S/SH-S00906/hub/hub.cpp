#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e6+5;
int n,k;
vector<int> g[N];
bool vis[N];
int bfs()
{
	queue<int>q;
	q.push(1);
	vis[1]=1;
	int p=0;
	while(!q.empty()){
		int width=q.size();
		for(int i=1;i<=width;++i){
			int cur=q.front();
			p=cur;
			q.pop();
			for(int j=0;j<(int)g[i].size();++j){
				if(!vis[g[i][j]]){
					q.push(g[i][j]);
					vis[g[i][j]]=1;
				}
			}
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(p);
	int cnt=0;
	while(!q.empty()){
		cnt++;
		int width=q.size();
		for(int i=1;i<=width;++i){
			int cur=q.front();
			q.pop();
			for(int j=0;j<(int)g[i].size();++j){
				if(!vis[g[i][j]]){
					q.push(g[i][j]);
					vis[g[i][j]]=1;
				}
			}
		}
	}
	
	return cnt;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(vis,0,sizeof(vis));
		int p=bfs();
		cout<<p-k+1<<"\n";
	}
	return 0;
}
