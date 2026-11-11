#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n;
int a1[N], len, ans;
char c1[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int len = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a1[i] >> c1[i];
		len += a1[i];
	}
	int r = n, l = 1;
	while(l < r) {
		int go = min(a1[l], a1[r]);
		if(c1[r] != c1[l])  {
			ans += go;
		}
		a1[l] -= go, a1[r] -= go;
		if(a1[l] == 0) l++;
		else r--;
	}
	cout << ans;
	return 0;
}
