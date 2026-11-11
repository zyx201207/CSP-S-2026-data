#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<int> len(n);
	vector<char> c(n);
	for (int i = 0; i < n; i++) {
		cin >> len[i] >> c[i];
	}
	
	int p = 0, q = n - 1;
	
	long long ans = 0;
	while (p < q) {
		if (len[p] == 0) ++p;
		else if (len[q] == 0) --q;
		else if (len[p] == len[q]) {
			if (c[p] != c[q]) ans += len[p];
			++p, --q;
		}
		else if (len[p] < len[q]) {
			if (c[p] == c[q]) {
				len[q] -= len[p];
				++p;
			}
			else {
				ans += len[p];
				len[q] -= len[p];
				++p;
			}
		}
		else if (len[p] > len[q]) {
			if (c[p] == c[q]) {
				len[p] -= len[q];
				--q;
			}
			else {
				ans += len[q];
				len[p] -= len[q];
				--q;
			}

		}
	}
	cout << ans;
	
	return 0;
}
