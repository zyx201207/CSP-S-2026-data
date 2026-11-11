#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c = getchar();
	ll x = 0, f = 1;
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar(); 
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
const int N = 5e5 + 5;
int n, fl, ans;
ll m, a[N], sum;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	n = read(), m = read();
	for(int i = 1; i <= n; ++i)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		while(a[i] * (i - fl) - sum > m && fl < i) 
			sum -= a[fl++];
		ans = max(ans, i - fl + 1);
		sum += a[i];
	}
	cout << ans;
	return 0;
}
