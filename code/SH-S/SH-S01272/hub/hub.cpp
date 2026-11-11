#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,INF=1e9;
int c,t;
int n,p,f[N][N],ans;
vector<int> vec[N];
bool vis[N];
void bfs(int x){
	queue<int> q;
	for(int i=1;i<=n;i++) vis[i]=0;
	f[x][x]=0; q.push(x);
	while(!q.empty()){
		int t=q.front(); q.pop(); vis[t]=1;
		for(int i=0;i<vec[t].size();i++)
			if(!vis[vec[t][i]]){
				q.push(vec[t][i]);
				f[x][vec[t][i]]=f[x][t]+1;
			}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>p; ans=INF;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=INF;
		for(int i=1;i<=n;i++) bfs(i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int res=0;
				for(int k=1;k<=n;k++){
					int dis=min(f[i][k],f[j][k]);
					res=max(res,dis);
				}
				ans=min(ans,res);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
