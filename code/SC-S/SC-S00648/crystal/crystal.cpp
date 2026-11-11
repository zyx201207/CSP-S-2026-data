#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int N = 5e5 + 9;

int s[N], d[N];
int a[N];

int result;
int n, m;
int c;
int p;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	for(int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	} 
	c = m;
	p = 1; 
	for(int i = 1; i <= n; i++) {
		if(p != 1) {
			c += a[p] - a[i - 1];
		}
		while(true) {
			if(p == n) {
				break;
			}
			if(d[p + 1] * (p - i + 1) <= c) {
				result = max(result, p - i + 2);
				c -= d[p + 1] * (p - i + 1); 
				p++;
			}else {
				break;
			}
//			cout << i << " " << p << " " << c << endl;
		}
	}
	cout << result << endl;
	return 0;
}