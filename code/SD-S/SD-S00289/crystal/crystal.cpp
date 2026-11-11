# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int n, m;
const int N = 5e5 + 5;
int a[N];

inline bool dengchashulie (int a[]) {
	sort (a + 1, a + 1 + n);
	int cha = a[n] - a[n - 1];
	for (int i = n - 1; i > 1; i -- ) {
		if (a[i] - a[i - 1] != cha) {
			return 0;
		}
	}
	return 1;
} 

int dif[N];

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	fst;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	if (dengchashulie (a)) {
		sort (a + 1, a + 1 + n);
		int ans = 0;
		if (! (a[n] - a[n - 1])) {
			cout << n << endl;
			return 0;
		}
		for (int i = n; i >= 1; i -- ) {
			if (m > 0) {
				m -= (a[n] - a[i - 1]);
				ans ++;
			}
			if (m == 0) {
				cout << ans << endl;
				return 0;
			} 
			if (m < 0) {
				cout << ans - 1 << endl;
				return 0;
			}
		}
	}
	sort (a + 1, a + 1 + n);
	for (int i = n; i >= 2; i -- ) {
		dif[i - 1] = a[i] - a[i -1];
	}
	sort (dif + 1, dif + n);
	if (dif[1]) {
		int ans = 0;
		for (int i = n - 1; i >= 1; i -- ) {
			int z = m;
			int cnt = 0;
			int sum = 0;
			while (z > 0) {
				for (int j = i; j >= max (1LL, i - cnt); j -- ) {
					sum += dif[i];
				}
				z -= sum;
				cnt ++;
			}
			if (! z) {
				ans = max (ans, cnt); 
			} 
			else {
				ans  = max (ans, cnt - 1);
			}	
		}
		cout << ans + 1 << endl;
		return 0;	
	}
	int ans = 0;
	int ling = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (! dif[i]) {
			ans ++;
			ling ++;
		}
		else {
			break; 
		}
	}
	for (int i = n - 1; i >= ling + 1; i -- ) {
		int z = m;
		int cnt = 0;
		int sum = 0;
		while (z > 0) {
			for (int j = i; j >= max (ling + 1LL, i - cnt); j -- ) {
				sum += dif[i];
			}
			z -= sum;
			cnt ++;
		}
		if (! z) {
			ans = max (ans, cnt); 
		} 
		else {
			ans  = max (ans, cnt - 1);
		}	
	}
	cout << ans + 1 + ling << endl;
	return 0;
}
 
