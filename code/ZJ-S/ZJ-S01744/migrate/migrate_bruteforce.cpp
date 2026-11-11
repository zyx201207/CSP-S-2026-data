#include <bits/stdc++.h>
#define int long long
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)s
#define mp make_pair
#define pb push_back

const int N = 1e6;
int n, d, a[N], ans, nxt[N];

bool chk(vector<int> v){
	int metas = 0;
	FOR(i, 0, (int)v.size() - 3){
		int cnt = 0;

		int cur = v[i + 1] - 1;
		if(v[i] < cur && a[v[i + 2]] - a[cur] <= d) cnt++;
		cur = v[i + 1] - 2;
		if(v[i] < cur && a[v[i + 2]] - a[cur] <= d) cnt++;

		if(cnt >= 2) return false;
		if(cnt == 1) metas++;
	}
	FOR(i, 0, (int)v.size() - 4){
		if(v[i + 2] - 1 > v[i + 1] && v[i + 1] - 1 > v[i]){
			if(a[v[i + 2] - 1] - a[v[i + 1] - 1] <= d && a[v[i + 3]] - a[v[i + 2] - 1] <= d){
				return false;
			}
		}
	}
	// if(metas == 1){for(auto i : v) cout << i << " "; cout << "\n";}
	return (metas == 1);
}

void solve(){
	FOR(i, 0, n + 1) nxt[i] = a[i] = 0;
	ans = 0;

	cin >> n >> d;
	FOR(i, 1, n) cin >> a[i];

	FOR(i, 1, n) nxt[i] = n + 1;
	FOR(i, 1, n){
		FOR(j, i + 1, n) if(a[j] <= a[i] + d){
			nxt[i] = j;
		}
	}

	FOR(i, 1, n){
		FOR(j, i + 1, n){
			int cur = i;
			vector<int> vec;
			vec.pb(cur);
			while(nxt[cur] < j){
				cur = nxt[cur];
				vec.pb(cur);
			}
			if(a[j] - a[cur] > d) continue;
			if(cur != j) vec.pb(j);
			ans += chk(vec);
		}
	}

	cout << ans << "\n";
	return ;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
0 7 14 21 28 35 42 49 56
X      XX       XX    XX
X      XX    XX       XX
X   XX       XX       XX
*/