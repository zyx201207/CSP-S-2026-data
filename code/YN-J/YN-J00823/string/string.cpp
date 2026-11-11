# include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long cnt, t;
map<long long, char>mp;

struct zfc {
	long long n;
	char m;
} s[maxn];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &t);
	for (long long i = 1; i <= t; i++) {
		scanf("%lld", &s[i].n);
		cin >> s[i].m;
	}
	long long zd = 1, yd = t;
	while (zd < yd) {
		char zc1 = s[zd].m;
		char zc2 = s[yd].m;
		long long zc3 = s[zd].n - s[yd].n;
		if (zc3 > 0) {
			if (zc1 != zc2) {
				cnt += s[yd].n;
			}
			s[zd].n = zc3;
			yd--;
		} else if (zc3 == 0) {
			if (zc1 != zc2) {
				cnt = cnt + s[zd].n;
			}
			zd++;
			yd--;
		} else if (zc3 < 0) {
			if (zc1 != zc2) {
				cnt = cnt + s[zd].n;
			}
			s[yd].n = s[yd].n - s[zd].n;
			zd++;
		}
	}
	printf("%lld", cnt);
	return 0;
}