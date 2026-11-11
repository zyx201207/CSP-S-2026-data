#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5,M=2e4+5;
int c,n,m,d,q,w[N],k[505],a[N],t[505][N],vis[50];
long long mn;
vector<int>v[50];
void dfs (int x,int y,long long cnt) {
	if (vis[x])return;
	vis[x]=1;
	if (x==y) {
		mn=min(mn,cnt);
		return;
	}
	if (!v[x].size())return;
	for (auto u:v[x]) {
		if (u!=x&&u==y) dfs(u,y,cnt+t[x][u]);
		if (u!=x&&u!=y) dfs(u,y,cnt+t[x][u]+t[x][x]);
	}
	vis[x]=0;
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m;i++) cin >> w[i];
	for ( int i = 1; i <= n;i++) {
		cin >> k[i]; 
		for ( int j = 1;j <= k[i];j++) {
			cin >> a[j] >> t[i][j];
		}
		for ( int i = 1; i <= k[i];i++) {
			for ( int j = 1; j <= k[i];j++) {
				if (i!=j) {
					v[a[i]].push_back(a[j]);
					v[a[j]].push_back(a[i]);
				}
			}
		}
	}
	for ( int i = 1,x,y; i <= q;i++) {
		cin >> x >> y;
		long long ans = w[x]+w[y];
		mn=2e18;
		dfs(x,y,ans);
		cout << mn << "\n";
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
