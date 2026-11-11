#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
int w[N],k[N],ans;
vector<int>a[505];
vector<int>t[505];
vector<int>G[N];
bool vis[N];
int T;
void dfs(int now,int co,int fin){
	if(now==fin)ans=min(ans,fin);
	for(int x:G[now]){
		for(int p:a[x]){
			if(p!=now&&!vis[p]){
				vis[p]=true;
				dfs(p,co+T*2,fin);
				vis[p]=false;
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,bb;
			cin>>aa>>bb;
			a[i].push_back(aa);
			t[i].push_back(bb);
			G[a[i][j]].push_back(i);
		}
	}
	/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
	*/
	T=t[1][1];
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=2e18;
		dfs(x,0,y);
		cout<<ans+w[x]+w[y]+T*2;
	}
	
	return 0;
}
