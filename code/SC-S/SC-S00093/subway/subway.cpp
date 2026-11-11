#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=6e5+500;
int w[MAXN],k[MAXN],x[MAXN],y[MAXN];
vector<vector<int>> a;
vector<vector<int>> t;
int c,n,m,d,q,r,ans=-1e18;bool vis[MAXN];
void dfs(int u,int sum){
	if(u==y[r]){
		ans=max(sum,ans);
		return;
	}
	sum+=w[u];
	for(auto v:a[u]){
		if(vis[v]==1) continue;
		vis[v]=1;
		dfs(v,sum+t[u][v]);
		vis[v]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		a.resize(k[i]*2+1),t.resize(k[i]*2+1);
		int aaa=0;
		for(int j=1;j<=n;j++){
			int aa,tt;
			cin >> aa >> tt;
			a[aaa].push_back(aa);
			a[aa].push_back(aaa);
			aaa=aa;
			t[aaa].push_back(tt);
			t[aa].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		r = i;
		vis[x[i]] = 1;
		dfs(x[i],0);
		cout << ans << "\n";ans=-1e18;
	}
	return 0;
}
/*
0 2 5 2 0 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/