#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int x{};
bool get_(ui x, int i) { return x & 1 << i; } 
bool more(ui l, ui y) {
	for (int i(31); i >= 0; --i) {
		if (get_(x, i) && get_(l, i) > get_(y, i)) return true;
		if (get_(x, i) && get_(l, i) < get_(y, i)) return false;
	}
	return false;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ui n, m;
	cin >> n >> m;
	ui li[200009];
	for (int i{}; i < n; ++i) cin >> li[i];
	for (int i(31); i >= 0; --i) {
		int num{};
		for (int j{}; j < n; ++j) num += get_(li[j], i);
		x |= 1 << i & -(num >= m);
	}
	sort(li, li + n, more);
	ui ans(-1);
	for (int i{}; i < m; ++i) ans &= li[i];
	cout << ans << flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

