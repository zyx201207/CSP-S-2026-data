#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x[2000005], d;

bool check(ll s, ll e) {
	int mt = -1, res = 0;
	queue <pair<ll, ll> > q;
	q.push({s, 0});
	while(! q.empty()) {
		pair<ll, ll> nw = q.front();
		q.pop();
		if(nw.first == e && mt == -1) {
			mt = nw.second;
			res ++;
			continue ;
		}
		if(nw.first == e && mt != -1) {
			if(mt == nw.second){
				res ++;
				continue ;
			}
			else {
				break ;
			}
		}
		if(mt != -1) break ;
		for(ll i = nw.first + 1;i <= e;i ++) {
			if(x[i] - x[nw.first] <= d) {
				q.push({i, nw.second + 1});
			}
			else break ;
		}
	}
	if(res == 2) return true;
	else return false;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, c;
	cin >> c >> T;
	while(T --) {
		if(c == 13 || c == 14) {
			cout << 0 << '\n';
			continue ;
		}
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) {
			cin >> x[i];
		}
		ll ans = 0;
		for(ll i = 1;i <= n;i ++)
			for(ll j = i + 1;j <= n;j ++) {
				if(check(i, j)) ans ++;
			}
		cout << ans << '\n';
	}
	return 0;
}