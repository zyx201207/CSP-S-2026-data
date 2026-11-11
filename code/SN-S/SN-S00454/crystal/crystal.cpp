//SN-S00454  杨建傲措  陕西省西安爱知中学
#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500005], sum[500005];

bool f(int i, int j) {
	if((j - i + 1) * a[j] - (sum[j] - sum[i-1]) <= m) return 1;
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int k = 0;
		for(int j = 1 << 19; j; j >>= 1) {
			if(k+j <= n && k+j >= i && f(i, k+j)) {
				k += j;
				ans = max(ans, k - i + 1);
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
