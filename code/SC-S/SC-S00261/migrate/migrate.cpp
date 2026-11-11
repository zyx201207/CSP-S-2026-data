#include <iostream>
using ll = long long;

const int N = 5005;

int n, c, l, r, ans, f[N], st[N];
ll d, a[N], fn[N], s[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	std::cin >> c >> T;
	while(T--) {
		std::cin >> n >> d;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) st[j] = fn[j] = f[j] = s[j] = 0;
			fn[i] = s[0] = 1;
			st[l = r = 1] = i;
			for(int j = i + 1; j <= n; ++j) {
				while(l <= r && a[j] - a[st[l]] > d) s[f[st[l]]] -= fn[st[l]], ++l;
				if(l <= r) {
					f[j] = f[st[l]] + 1;
					fn[j] = s[f[st[l]]];
					if(fn[j] == 2) ++ans;
					while(l <= r && f[st[r]] > f[j]) s[f[st[r]]] -= fn[st[r]], --r;
					st[++r] = j, s[f[j]] += fn[j];  
				}
			}
		}
		std::cout << ans << '\n';
	}
}