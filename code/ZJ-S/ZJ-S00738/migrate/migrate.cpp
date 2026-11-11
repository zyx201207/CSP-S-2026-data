#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e16;
int c,t;
int n,d;
int x[5005];
vector<int>g[5005];
bool vis[5005];
vector<int>dis[5005];
vector<int>cnt[5005];
struct Edge{
	int u,v;
};
vector<Edge>e;
int tot = 0;
vector<int>ng[5005];
int dg[5005];
void bfs(int s){
	for(int i = 1;i<=n;i++)vis[i] = 0;
	dis[s][s] = 0;
	cnt[s][s] = 1;
	vis[s] = 1;
	queue<int>q;
	q.push(s);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v:g[u]){
			if(vis[v])continue;
			vis[v] = 1;
			dis[s][v] = dis[s][u]+1;
			q.push(v);
		}
	}
	for(int i = 1;i<=n;i++)ng[i].clear();
	for(int i = 1;i<=tot;i++){
		int u = e[i].u;
		int v= e[i].v;
		if(dis[s][u]+1==dis[s][v]){
			ng[u].push_back(v);
			dg[v]++;
		}
	}
	q.push(s);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v:ng[u]){
			dg[v]--;
			cnt[s][v]+=cnt[s][u];
			if(dg[v]==0)q.push(v);
		}
	}
}
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	e.resize(30000005);
	for(int i = 1;i<=5002;i++){
		dis[i].resize(5005);
		cnt[i].resize(5005);
	}
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			g[i].clear();
			cin>>x[i];
		}
		tot = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(abs(x[j]-x[i])>d)break;
//				cout<<"link:"<<i<<" "<<j<<'\n';
				g[i].push_back(j);
				e[++tot]={i,j};
			}
		}
		for(int i =1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dis[i][j] = inf;
				cnt[i][j] = 0;
			}
		}
		for(int i =1;i<=n;i++){
			bfs(i);
		}
		int ans = 0;
		for(int u = 1;u<=n;u++){
			for(int v= u+1;v<=n;v++){
//				cout<<dis[u][v]<<":"<<cnt[u][v]<<" ";
				if(cnt[u][v]==2)ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 7
1 2 4 8 10 14 17 20 21 25
*/
