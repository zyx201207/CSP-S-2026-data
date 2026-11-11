#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
struct node{
	bool bit[31];
	ll a;
	bool choose;
}num[maxn];
ll n, m, tmp;
ll cimi2[31], ans = 0, cnt;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	cimi2[0] = 1;
	cimi2[1] = 2;
	for (int i = 2; i <= 30; i ++) {
		cimi2[i] = cimi2[i - 1] * 2;
	}
	for (int i = 1; i <= n; i ++) {
		tmp = read();
		num[i].a = tmp;
		for (int j = 30; j >= 0; j --) {
			if (tmp >= cimi2[j]) {
				tmp -= cimi2[j];
				num[i].bit[j] = true;
			}
			else {
				num[i].bit[j] = false;
			}
		}
		num[i].choose = true;
	}
	for (int j = 30; j >= 0; j --) {
		cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (num[i].bit[j] == true && num[i].choose == true) cnt ++;
		}
		if (cnt >= m) {
			for (int i = 1; i <= n; i ++) {
				if (num[i].bit[j] != true) num[i].choose = false;
			}
			ans += cimi2[j];
		}
	}
	printf("%lld", ans);
	return 0; 
}
