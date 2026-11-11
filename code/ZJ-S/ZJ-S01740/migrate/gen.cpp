#include <bits/stdc++.h>
#define ll long long
const int N = 2e6 + 5;
int main() {
	freopen("data.in", "w", stdout);
	std::cout << "13 1\n";
	std::cout << "300 40000\n";
	int d = 40000;
	std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int pos = rng() % 300;
	std::vector<ll> a(300);
	a[pos] = rng() % 800000 + 600000;
	std::map<ll, int> vis;
	for (int i = 0; i < pos - 1; ++i) {
		do {
			// [a[pos] - d, a[pos] - 1]
			a[i] = rng() % d + a[pos] - d;
		} while (vis[a[i]]);
		vis[a[i]] = 1;
	}
	for (int i = pos + 1; i < 300; ++i) {
		do {
			// [a[pos] + 1, a[pos] + d]
			a[i] = rng() % d + a[pos] + 1;
		} while (vis[a[i]]);
		vis[a[i]] = 1;
	}
	std::sort(a.begin(), a.end());
	for (int x : a) std::cout << x << " ";
}