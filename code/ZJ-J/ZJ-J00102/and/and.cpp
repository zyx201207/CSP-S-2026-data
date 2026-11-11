#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200010;
int n, m;
ll a[N];
int s[N][50];
bool vis[N];

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 40 && a[i]; j++)
			s[i][j] = a[i] % 2, a[i] >>= 1;
	ll ans = 0;
	for (int i = 40; i >= 1; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if(!vis[j] && s[j][i] == 1) ++cnt;
		if(cnt < m) continue;
		for (int j = 1; j <= n; j++)
			if(!s[j][i]) vis[j] = true;
		ans += 1ll << (i - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
