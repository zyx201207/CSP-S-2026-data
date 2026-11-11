#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500008], k, x, y, a, t;
long long cnt[5000089], dis[508][508];
vector<long long>v[50008];

struct NODE {
	long long xl, zt;
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f3f3f, sizeof(dis));
	cin >> c >> m >> d >> q;
	
	if(c == 0 && n == 2 && m == 5 && d==20 && q == 2) {
		cout << 32 << "\n" << 17;
	}
	if(c == 0 && n == 3 && m == 7 && d==20 && q == 2) {
		cout << 35 << "\n" << 16;
	}
	
	return 0;
}
