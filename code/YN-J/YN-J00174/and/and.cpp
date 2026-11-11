#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
long long S[200005];


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	sort(S, S + n);
	cout << S[n - m];
	return 0;
}