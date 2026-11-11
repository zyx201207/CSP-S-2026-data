//齐君豪 西安市含光中学 SN-S00442
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;

int n;
ll m, a[N];
ll s[N];
int ans;

bool check(int i, int x) {
	int j = i - x + 1;
	ll now = s[i] - s[j - 1];
	ll goal = a[i] * (ll)x;
	ll p = goal - now;
	if(p <= m) return true;
	else return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++) {
		int L = 0, R = i + 1;
		while(L + 1 < R) {
			int M = (L + R) >> 1;
			if(check(i, M)) L = M;
			else R = M;
		}
		ans = max(ans, L);
	}
	printf("%d\n", ans);
	return 0;
} 
