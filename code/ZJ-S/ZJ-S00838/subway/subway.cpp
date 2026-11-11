#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+505;
const int M = 505;
struct node{
	long long x, w;
};
vector<node> G[N];
long long w[N];
long long c, n, m, d1, q;
long long d[M][M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d, 0x3f, sizeof d);
	cin >> c >> n >> m >> d1 >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x, w;
			cin >> x >> w;
			G[i+m].push_back({x, w});
			G[x].push_back({i+m, w});
		}
	}
	for(int i = 1; i <= m; i++){
		for(auto v: G[i]){
			for(auto z: G[i]){
				d[v.x-m][z.x-m] = min(d[v.x-m][z.x-m],v.w+z.w);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
		d[k][k] = 0;
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		long long ans = w[x]+w[y];
		long long sum = LLONG_MAX;
		for(auto v: G[x]){
			for(auto z: G[y]){
				sum = min(sum, v.w+z.w+d[v.x-m][z.x-m]);
			}
		}
		cout << ans+sum << "\n";
	}
	return 0;
}
