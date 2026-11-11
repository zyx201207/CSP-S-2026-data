#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	//int sum{};
	/*cin >> n;
	string s;
	for (int i{}; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
		string str;
		cin >> str;
		for (int j{}; j < x; ++j) s += str;
	}
	int ans{};
	for (int i{}; i < sum >> 1; ++i) {
		if (s[i] != s[sum - 1 - i]) ++ans;
	}
	cout << ans << flush;*/
	cin >> n;
	pair<ll, char> li[200009];
	for (ll i{}; i < n; ++i) {
		cin >> li[i].first >> li[i].second;
	}
	ll ans{};
	ll p_1{}, p_2(n-1);
	while (p_1 < p_2) {
		bool b(li[p_1].second != li[p_2].second);
		int x(min(li[p_1].first, li[p_2].first));
		ans += x & -b;
		li[p_1].first -= x, li[p_2].first -= x;
		p_1 += !li[p_1].first;
		p_2 -= !li[p_2].first;
	}
	cout << ans << flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


