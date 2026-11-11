#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
ll ccf,n,m,d,q,w[N],dp[N][N],fa[N][N];
vector<ll> a[N],k[N];
map<ll,ll> vis[N];
ll Find(ll id,ll x){
	if(fa[id][x]==x)	return x;
	return fa[id][x]=Find(id,fa[id][x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccf>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll mama;
		cin>>mama;
		for(int j=1;j<=m;j++){
			fa[i][j]=j;
		}
		ll last=0;
		for(int j=1;j<=mama;j++){
			int v,w;
			cin>>v>>w;
			fa[i][Find(i,v)]=Find(i,last);
			last=v;
			vis[i][v]=j-1;
			a[i].push_back(v);
			k[i].push_back(w);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=0x3f3f3f3f3f3f3f3f;
			if(i==j)	dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int u=1;u<=m;u++){
			for(int v=1;v<=m;v++){
				if(u==v){
					dp[u][v]=0;
					continue;
				}
				if(Find(i,u)==Find(i,v)){
					dp[u][v]=min(dp[u][v],k[i][vis[i][u]]+k[i][vis[i][v]]);
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dp[u][v]+w[u]+w[v]<<'\n';
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
