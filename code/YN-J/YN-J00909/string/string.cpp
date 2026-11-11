#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e8 + 5;
int n;
ll ans;
char S[N];
int x;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int num;
		char id;
		cin >> num >> id;
		for (int j = 0; j < num; ++j) {
			S[x] = id;
			x++;
		}
	}
	int i = 0, j = x - 1;
	for (; i <= j, j >= i; ++i, --j) {
		if (S[i] != S[j]) {
			S[j] = S[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}