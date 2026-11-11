#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch & 15);
		ch = getchar();
	}
	return x * f;
} 
const int N = 5e5 + 5;
int n, m, a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i <= n;++ i)
		a[i] = read();
	sort(a + 1, a + n + 1);
	int Tmp = 1, res = 1, Cnt = 0;
	for(int i = 2;i <= n;++ i) {
		Cnt += (i - Tmp) * (a[i] - a[i - 1]);
		while(Tmp <= i && Cnt > m) {
			Cnt -= (a[i] - a[Tmp]);
			++ Tmp;
		}
		res = max(res, i - Tmp + 1);
	}
	cout << res;
	return 0;
}
