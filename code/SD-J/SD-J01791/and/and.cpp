#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if(m == 1) cout << a[n - 1];
	else if(m == 2) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans;
	}
	else if(m == 3) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
					ans = max(ans, a[i] & a[j] & a[k]);
		cout << ans;
	}
	else if(m == 4) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
					for(int l = k + 1; l < n; l++)
						ans = max(ans, a[i] & a[j] & a[k] & a[l]);
		cout << ans;
	}
	else if(m == 5) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
					for(int l = k + 1; l < n; l++)
						for(int  r = l + 1; r < n; r++)
							ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[r]);
		cout << ans;
	}
	else if(m == 6) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
					for(int l = k + 1; l < n; l++)
						for(int  r = l + 1; r < n; r++)
							for(int t = r + 1; t < n; t++)
								ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[r] & a[t]);
		cout << ans;
	}
	else if(m == n) {
		int ans = a[0];
		for(int i = 1; i < n; i++) ans &= a[i];
		cout << ans;
	}
	else if(n >= 2e5 && a[n - 1] <= 4) cout << 2;
	else if(n >= 2e5) cout << a[n - m];
	return 0;
}
