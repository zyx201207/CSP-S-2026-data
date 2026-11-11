#include<bits/stdc++.h>
using namespace std;
const int N = 2000010;
#define I inline
#define gc getchar
#define pc putchar
#define int long long
I int read() {
	int x = 0, f = 1; char ch = gc();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = gc();}
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x * f;
}
I void write(int x) {
	if(x < 0) pc('-'), x = -x;
	if(x == 0) {pc('0'); return ;}
	int tot = 0; char s[20];
	while(x) {
		s[tot++] = x % 10 + '0';
		x /= 10;
	}
	while(tot--) pc(s[tot]);
}
int c, t, n, d, x[N], le[N], ri[N], cnt[N];
void sub1() {
	for(int i = 1, j = 1; i <= n; i++) {
		j = i + 1;
		while(j <= n && x[j] - x[i] <= d) j++;
		ri[i] = j - 1;
	}
	ri[n] = n + 1;
	for(int i = n; i; i--) {
		int j = i - 1;
		while(j && x[i] - x[j] <= d) j--;
		le[i] = j + 1;
	}
	le[1] = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int len = ri[i] - 1, lst = ri[i];
		for(int j = i; j <= ri[i]; j++) cnt[j] = 1;
		for(int j = ri[i] + 1; j <= n; j++) cnt[j] = 3;
		for(int j = ri[ri[i]]; j <= n && lst <= n; j = ri[j]) {
			if(le[j] == j && ri[j] == j) {
				j++; lst = ri[j]; j = ri[ri[j]], len = ri[j] - j;
				continue;
			}
			if(le[j] < lst - 1) break;
			else if(le[j] == lst - 1) {
				if(cnt[lst - 1] == 1) {
					int k = j;
					while(k > lst && le[k] == lst - 1) cnt[k] = 2, k--;
				}
				else break;
			}
			else {
				assert(le[j] == lst);
				int pos = ri[lst - 1];
				for(int k = pos + 1; k <= j; k++) cnt[k] = cnt[lst];
				if(cnt[lst] == 1) {
					for(int k = lst + 1; k <= ri[lst - 1]; k++) cnt[k] = 2;
					if(len > 2) {
						for(int k = lst + 1; k <= ri[lst - 2]; k++) cnt[k] = 3;
					}
				}
			}
			if(cnt[j] > 2) break;
			len = j - lst;
			lst = j;
		}
		for(int j = ri[i] + 1; j <= n; j++) if(cnt[j] == 2) {
			ans++;
		}
	}
	write(ans); pc('\n');
}
void sub2() {
	int step = d / (x[2] - x[1]);
	if(step == 0 || step == 1) {puts("0"); return ;}
	int len = 2 * step - 1;
//	cout << "len = " << len << ' ' << n << '\n';
	if(len >= n) puts("0");
	else {write(n - len); pc('\n');}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--) {
		n = read(), d = read();
		for(int i = 1; i <= n; i++) x[i] = read();
		if(n == 1) {
			puts("0");
			continue;
		}
		if(c >= 13 && c <= 14) {
			sub2();
		}
		else {
			sub1();
		}
	}
	return 0;
}
