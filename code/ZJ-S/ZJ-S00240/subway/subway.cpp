#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
const int N = 505;
typedef long long ll;
ll w[M];
int c,n,m,d,q;
int way[N][M];
int t[N][M];
ll a[M];
vector<int> e[M];
void dfs(int x){
	int l;
	for(int ii = 0;ii < e[x].size();ii++){
		int i = e[x][ii];
		for(int j = 1;j <= way[i][0];j++){
			if(way[i][j]==x){
				l=j;
				break;
			}
		}
		for(int j = 1;j <= way[i][0];j++){
			int tx = way[i][j];
			if(tx==x) continue;
			if(a[tx]>a[x]+t[i][j]+t[i][l]){
				a[tx]=a[x]+t[i][j]+t[i][l];
				dfs(tx);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> way[i][0];
		int k = way[i][0];
		for(int j = 1;j <= k;j++){
			cin >> way[i][j] >> t[i][j];
			e[way[i][j]].push_back(i);
		}
	}
	while(q--){
		memset(a,0x3f,sizeof(a));
		int u,v;
		cin >> u >> v;
		ll ans = w[u]+w[v];
		a[u]=0;
		dfs(u);
		ans+=a[v];
		cout << ans << "\n";
	}
	return 0;
}