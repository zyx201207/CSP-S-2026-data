#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll maxn = 5005;

ll Read() {
	char c;
	ll num = 0, f = 1;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c - '0');
		c = getchar();
	}
	return num * f;
}

ll cnt, c, t, n, d, x[maxn];
void DFS(ll u, ll v, ll f, ll p) {
	if (p == f + 1) {
		if (u == v) {
			++cnt;
		}
		return;
	}
	for (ll i = u + 1; i <= v; ++i) {
		if (x[i] - x[u] <= d) {
			DFS(i, v, f, p + 1);
		}
	}
}

ll Get_f(ll u, ll v) {
	ll now = u, res = 0;
	while (now != v) {
		if (x[v] - x[now] <= d) {
			++res;
			now = v;
			break;
		}
		for (ll i = now + 1; i <= v; ++i) {
			if (x[i] - x[now] > d) {
				now = i - 1;
				++res;
				break;
			}
		}
	}
	return res;
}

bool Fly(ll u, ll v) {
	for (ll i = u + 1; i <= v; ++i) {
		if (x[i] - x[i - 1] > d) {
			return false;
		}
	} 
	return true;
}

ll ans;
void Solve() {
	for (ll i = 1; i < n; ++i) {
		for (ll j = i + 1; j <= n; ++j) {
			cnt = 0;
			if (Fly(i, j) == false) {
				break;
			}
			ll f = Get_f(i, j);
			DFS(i, j, f, 1);
			if (cnt == 2) {
				++ans;
			}
		}
	}
	return;
}

void Input() {
	c = Read(), t = Read();
	while (t--) {
		ans = 0;
		n = Read(), d = Read();
		for (ll i = 1; i <= n; ++i) {
			x[i] = Read();
		}
		Solve();
		printf("%lld\n", ans);
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	Input();
	return 0;
}
/*
[16:20]其它题都不会，这道一眼暴力吃分
[17:25]回头干了一会儿 T1，现在才写完，样例1,2能过耶~~~
[17:29]样例3栽了QWQ
[18:06]才发现样例2（2）4->5 飞不过去啊？
[18:09]样例1,2过了，样例3大错特错。
[18:32]算鸟，CSP-S2就到此为止吧！
*/
//心怀荣耀，勇往直前！
//OTOI2026