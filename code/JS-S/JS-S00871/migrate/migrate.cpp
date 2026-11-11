/*
 * 15:17 skip T2,observe the task
 * try O(n^2) (40pts)
 * too difficult,i will baosou (8pts) 555
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int inf=0x3f3f3f3f3f3f3f3fLL;
bool vis[N];
vector<int> g[N];
int c,t,n,d,ans,x[N],cnt;
int dist[N][N];
void dfs(int u,int dep,int goal,int curdep){
	if (curdep==dep){
		cnt+=(u==goal);
		return ;
	}
	for (int v:g[u]){
		dfs(v,dep,goal,curdep+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		ans=0;
		for (int i=1;i<=n;i++)
			fill(dist[i]+1,dist[i]+1+n,inf);
		for (int i=1;i<=n;i++){
			cin >> x[i];
			g[i].clear();
			dist[i][i]=0;
		}
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (x[j]-x[i]<=d){
					dist[i][j]=1;
					dist[j][i]=1;
					g[i].push_back(j);
				}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (dist[i][j]>dist[i][k]+dist[k][j])
						dist[i][j]=dist[i][k]+dist[k][j];
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (dist[i][j]!=inf){
					cnt=0;
					dfs(i,dist[i][j],j,0);
					if (cnt==2) ans++;
				}
		cout << ans << endl;
	}
	return 0;
}
