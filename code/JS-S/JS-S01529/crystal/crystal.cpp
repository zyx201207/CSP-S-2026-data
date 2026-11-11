#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n;
	ll m;
	cin >> n >> m;
	vector<ll> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	sort(v.begin() + 1, v.end());

	int l = n, ans = 0;
	ll s = v[n];
	for(int i = n; i >= 1; i--){
		while(l >= 2 && v[i] * (i - l + 2) - (s + v[l - 1]) <= m)
			s += v[--l];

		ans = max(ans, i - l + 1);
		s -= v[i];
	}

	cout << ans;

	return 0;
}