#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=505;
const int M=5e5+10;
int c,n,m,d,q;
int w[M];
bool vis[M], flag = false;
int g1[M], g2[M][M];
vector<int> g3[M], id[M];
int ans;
int dfs(int u,int v){
	if(u==v){
		return 0;
	}
	if(flag)
	{
		return ans;
	}
	vis[u]=true;
	for(auto s : id[u])
	{
		for(auto k : g3[s]){
			if(vis[k]){
				continue;
			}
			if(k==u){
				continue;
			}
			else if(k==v){
				ans+=g1[k],ans+=g2[k];
				flag = true;
				return ans;
			}
			else
			{
				dfs(k,v);
			}
			/*
			if(k==v){
				ans+=g1[k],ans+=g2[k];
				return ans;
			}
			else{
				dfs(k, v);
			}
			*/
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(vis, false, sizeof(vis));
	memset(g1, 0, sizeof(g1));
	memset(g2, 0, sizeof(g2));
	memset(g3, 0, sizeof(g3));
	memset(id, 0, sizeof(id));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g1[i]=w[i];
	} 
	int ki;
	for(int i=1;i<=n;i++){
		cin>>ki;
		int a,t;
		for(int j=1;j<=ki;j++){
			cin>>a>>t;
			id[a].push_back(i);
			g3[i].push_back(a);
			g2[a][i]=t;
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0, flag = false;
		ans+=g1[x], ans+=g2[x];
		ans+=g1[y], ans+=g2[y];
		//dfs(x,y);
		//cout<<dfs(x,y)<<endl;
		cout << ans<<endl;
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
 */