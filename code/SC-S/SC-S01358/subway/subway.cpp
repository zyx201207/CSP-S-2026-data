#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1012,inf = 1e12;
short mei_shen_me_yong;//没什么用
int c,n,m,d,q;
ll dp[MAXN][MAXN]; 
ll dis[MAXN];
vector<int> temp;
ll tmp[MAXN][MAXN];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				int old = dp[i][j];
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
				if(old != dp[i][j])dp[i][j] -= 2*dis[k];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>mei_shen_me_yong>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dis[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i == j)dp[i][j] = 0;
			else dp[i][j] = inf;
			tmp[i][j] = inf;
		}
	}
	for(int i=1;i<=n;i++){
		int tn;
		cin>>tn;
		temp.clear();
		for(int j=1;j<=tn;j++){
			ll v,w;
			cin>>v>>w;
			temp.push_back(v);
			tmp[i][v] = tmp[v][i] = min(tmp[i][v],w);
		}
		int sz = temp.size();
		for(int j=0;j<sz;j++){
			int u = temp[j];
			for(int k=j+1;k<sz;k++){
				int v = temp[k];
				if(u != v)
				dp[u][v] = dp[v][u] = dis[u] + dis[v] + tmp[i][v] + tmp[i][u];
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	floyd();
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<dp[u][v]<<'\n';
	} 
	return 0;
}