#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5,N2=205;
int c,n,m,d,q;
int ans=1e18;
int w[N];
int b[N2][N];
bool vis[N2][N];
vector<pii>g1[N];
int g2[N2][N];
void dfs(int x,int u,int ed,int sum){
	if(sum>ans)return ;
	if(u==ed){
		ans=min(ans,sum+b[x][u]);
		return ;
	}
	
	if(g2[x][u]){
		dfs(x,g2[x][u],ed,sum);
	}else{
		return ;
	}
	for(int i=0;i<g1[u].size();i++){
		if(g1[u][i].first==x)continue;
		dfs(g1[u][i].first,u,ed,sum+g1[u][i].second+b[x][u]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,lsta=0;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			b[i][a]=t;
			g1[a].push_back({i,t});
			g2[i][lsta]=a;
			lsta=a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<g1[x].size();i++){
			dfs(g1[x][i].first,x,y,g1[x][i].second);
		}
		cout<<ans+w[x]+w[y]<<'\n';
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
