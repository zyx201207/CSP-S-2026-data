#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
const int N = 200005;
ll num[N];
vector<ll>a;
bool vi[N];
ll ans = 0;

void dfs(ll k) {
	if (k == m) {
		ll res = a[0];

		for (int i = 0 ; i < (int)a.size(); i++) {



			res &= a[i];
		}

		ans = max(ans, res);


		return ;

	}



	for (int i = 1 ; i <= n; i++) {

		if (!vi[i]) {
			a.push_back(num[i]);
			vi[i] = 1;
			dfs(k + 1);
			a.pop_back();
			vi[i] = 0;
		}

	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1 ; i <= n ; i++) {

		cin >> num[i];
	}

	dfs(0);
	cout << ans;
	return 0;
}