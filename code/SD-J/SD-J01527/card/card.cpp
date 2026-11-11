#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define ___prique_mx priority_queue<vector<ll>>
#define ___prique_mn priority_queue<vector<ll, greater<ll>>>
#define endl '\n'
const int N = 5e5 + 10;
ll a[N], cnt[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	for(ll i = 1; i <= n; ++ i) cin >> a[i];
	vector<ll> b;
	for(ll i = 1; i <= n; ++ i) {
		b.resize(n);
		for(ll j = i; j <= n; ++ j) {
			if(b[lower_bound(b.begin(), b.end(), a[j]) - b.begin()] != a[j]){
				b.push_back(a[j]);
			}else {
				b.erase(lower_bound(b.begin(), b.end() + 1, a[j]), b.end());
			}
		}
		for(ll x : b) {
			cnt[x] ++;
		}
	}
	for(ll i = 1; i <= m; ++ i) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
