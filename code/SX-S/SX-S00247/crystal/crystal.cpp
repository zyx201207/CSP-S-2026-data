#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a[500010], d[500010], ans, sum[500010], sum2[500010], sm[500010], flag[500010], sum1[500010], vis[500010],
cnt1,
cnt = 1;
ll summ;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int flagA;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flagA = 1;
	}
	if (flagA == 0) {
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + 1;
			summ += sum[i];
			if (summ > m) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) {
		d[i] = a[i + 1] - a[i];
	}

	ll st = 1, cnt2 = 1, cnt3 = 1;
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + d[i];
		sm[i] = sm[i - 1] + d[i];
//		sum1[cnt1] += sm[i];			//sum1 每一个分块的不下降区间de zong quanzhi
		if (d[i] > d[i + 1] && flag[i] == 0) {				//考虑最后一个数字是否将其划分为段
//			if (i != (n - 1) && d[i + 1] == 0) {
//				flag[i + 1] = 1;
//				continue;
//			}
			cnt1++;
			vis[cnt2] = i + 1;
			cnt2++;
			sm[i] = 0;
		}
	}

	for (int i = 1; i <= cnt1; i++) {
		for (int j = st; j <= n; j++) {
			sum2[cnt] += sum[j];
			if (sum2[cnt] > m) {
				ans = max(ans, j - st);
				cnt++;
				st = vis[cnt3];
				cnt3++;
				sum[j] = sm[j];
			}
		}
	}
	cout << ans + 1 << '\n';
	return 0;
}