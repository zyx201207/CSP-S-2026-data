#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int ans = 0;
void dfs (int s, int i, int stp) {
	if (stp == m) {
		ans = max (ans, s);
		return;
	}
	for (int j = i + 1; j + (m - stp) - 1 <= n; ++j) {
		dfs ((s & a[j]), j, stp + 1);
	}
}
unordered_set<int> sth;
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	for (int i = 0; i <= 30; ++i) {
		sth.insert (1 << i);
	}
	
	bool A = true, B = true;
    cin >> n >> m;
	if (!sth.count (n)) {
		B = false;
		
	}
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
		if (a[i] + 1 != i) {
			B = false;
		}
		if (!sth.count (a[i] + 1)) {
			A = false;
		}
    }
	if (n <= 20) {
		dfs (INT_MAX, 0, 0);
		cout << ans << endl;
	} else if (m == 1) {
		for (int i = 1; i <= n; ++i) {
			ans = max (a[i], ans);
		}
		cout << ans << endl;
	} else if (m == n) {
		for (int i = 1; i <= n; ++i) {
			ans &= a[i];
		}
		cout << ans << endl;
	} else if (m == 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans = max (ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
	} else if (A) {
		sort (a + 1, a + n + 1);
		cout << a[n - m + 1] << endl;
	} else if (B) {
		int i = 1;
		while (1) {
			if (m >= (n >> i)) {
				cout << (((1 << i) - 1) << (int (log2 (n)) - i)) << endl;
				break;
			}
			i <<= 1;
		}
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
} 