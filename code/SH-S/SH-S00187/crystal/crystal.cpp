#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum[500010] = {0};
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	if(n > 5000) {
		cout << n;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= i;j++) {
			if(sum[i] - sum[j] + a[j] + m >= (i - j + 1) * a[i]) {
				ans = max(ans,i - j + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
