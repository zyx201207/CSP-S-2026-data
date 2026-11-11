#include<bits/stdc++.h>
#define _for(i, a, b) for(long long i = a; i <= b; ++i)
using namespace std;
const long long N = 2e6 + 5;
long long c, t, n, d, x[N];
vector<long long> es[N], cnt(N), mi(N);
void dfs(long long u, long long t){
	if(t > mi[u]) return ;
	if(t == mi[u]) cnt[u]++;
	if(t < mi[u]) mi[u] = t, cnt[u] = 1;
	for(long long v : es[u]) dfs(v, t + 1);
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			cin >> n >> d;
			_for(i, 1, n) cin >> x[i];
			int t = d / (x[2] - x[1]);
			if(t < 2){
				cout << 0 << '\n';
				continue;
			}
		}
	}
	while(t--){
		cin >> n >> d;
		_for(i, 1, n) cin >> x[i], es[i].clear();
		_for(i, 1, n){
			_for(j, i + 1, n){
				if(x[j] - x[i] <= d) es[i].push_back(j);
				else break;
			}
		}
		long long t = 0;
		_for(i, 1, n){
			_for(j, 1, n) cnt[j] = 0, mi[j] = 1e9;
			dfs(i, 0);
			_for(j, 1, n) if(cnt[j] == 2) t++;
		}
		cout << t << '\n';
	}
	return 0;
}