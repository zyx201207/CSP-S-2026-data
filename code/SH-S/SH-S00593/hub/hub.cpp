#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
vector<int> graph[300000];
int fa[300000];
int find(int x){return (fa[x] == x ? x : fa[x] = find(fa[x]));}
int dis[300][300];
void dfs(int pos,int rt,int fa){
	if(pos != rt){
		dis[rt][pos] = dis[rt][fa] +1;
	}
	for(int i=0;i<graph[pos].size();i++){
		if(graph[pos][i] != fa) dfs(graph[pos][i], rt, pos);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) graph[i].clear(), fa[i] = i;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = 0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			graph[x].push_back(y); graph[y].push_back(x);
		}
		for(int i=1;i<=n;i++) dfs(i,i,0);
		int ans = 1e18;
		for(int i=1;i<(1<<n);i++){
			for(int j=1;j<=n;j++) fa[j] = j;
			int tnc = 0;
			for(int j=1;j<=n;j++) if(i&(1<<(j-1))) tnc++;
			if(tnc != k) continue;
			for(int j=1;j<=n;j++) if(i&(1<<(j-1))){
				for(int k=0;k<graph[j].size();k++){
					if(i&(1<<(graph[j][k]-1))){
						fa[find(j)] = find(graph[j][k]-1);
					}
				}
			}
			int cnt = 0;
			for(int j=1;j<=n;j++) if(i&(1<<(j-1))){
				if(find(j) == j) cnt++;
			}
			if(cnt <= 2){
				int sum = 0; 
				for(int j=1;j<=n;j++) if(!(i&(1<<(j-1)))){
					int mn = 1e18;
					for(int k=1;k<=n;k++) if(i&(1<<(k-1))){
						mn = min(mn, dis[j][k]);
					}
					sum = max(sum, mn);
				}
				ans = min(ans, sum);
			}
		}
		cout << ans << endl;
	}
	
}
