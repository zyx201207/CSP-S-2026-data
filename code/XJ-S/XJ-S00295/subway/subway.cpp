#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int c, n, m, d, q, x, y;
int w[500005], k[505], t[500005], a[500005];
bool flag[500005];
vector<pair<int, int> > v[500005];
queue<int> qu;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
			cin >> a[j] >> t[j];
		for(int j = 1; j <= k[i]; j++){
			for(int jj = 1; jj <= k[i]; jj++){
				v[a[j]].push_back({a[jj], t[j]+t[jj]});
			}
		}
	}
	for(int i = 1; i <= m; i++) sort(v[i].begin(), v[i].end());
	while(q--){
		int sum[500005];
		memset(sum, 0x3f, sizeof(sum));
		memset(flag, 0, sizeof(flag));
		cin >> x >> y;
		sum[x] = 0;
		qu.push(x);
		while(!qu.empty()){
			int sx = qu.front();
			qu.pop();
			for(auto ss : v[sx]){
				int xx = ss.fi;
				int tt = ss.se;
				sum[xx] = min(sum[xx], sum[sx]+tt);
				if(!flag[xx]){
					qu.push(xx);
					flag[xx] = true;
				}
			}
		}
		cout << sum[y]+w[y]+w[x] << '\n';
	}
	return 0;
}

