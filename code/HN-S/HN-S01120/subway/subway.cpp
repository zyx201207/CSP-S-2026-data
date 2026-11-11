#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q;
int w[N],a[510][5010],t[510][5010];
int vis[N],dist[N];
vector<pair<int,int>>vec[N];
void bfs(int &x,int &y){
	fill(dist+1,dist+n+1,LLONG_MAX);
	memset(vis,0,sizeof vis);
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(x);
	dist[1]=0;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		if(u==y)break;
		if(vis[u])continue;
		vis[u]=1;
		for(auto tmp:vec[u]){
			int v=tmp.first;
			int w=tmp.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			vec[a[i][j]].push_back({j,a[i][j]+w[i]});
		}			
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		cout<<dist[y]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
