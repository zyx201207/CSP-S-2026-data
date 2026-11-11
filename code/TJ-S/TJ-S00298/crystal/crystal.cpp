#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll a[N], s[N];
int dp[N];
int n;
ll m, d;

void solveb() {
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		if(sum + 1ll * i * d > m) {
			cout << i << endl;
			break;
		}
		sum += 1ll * i * d;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int okb = 1;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	d = a[2] - a[1];
	for(int i = 2; i <= n; i++) {
		if(a[i] - a[i-1] != d) {
			okb = 0;
			break;
		}
	}
	if(okb) {
		solveb();
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = 1;
		if(a[i] == a[i-1]) {
			dp[i] = dp[i-1] + 1;
		} else {
			for(int j = 1; j < i; j++) {
				ll sum = s[i-1] - s[j-1];
				ll jia = 1ll * (i - j) * a[i] - sum;
				if(jia <= m) {
					dp[i] = max(i - j + 1, dp[i]);
					break;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
} 
