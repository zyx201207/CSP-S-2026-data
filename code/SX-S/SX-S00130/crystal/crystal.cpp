#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
long long m, a[maxn];

struct node {
	int trunum;
	int les;
} num[maxn];

bool cmp (node a, node b) {
	if (a.les < b.les)
		return true;
	else if (a.les == b.les && a.trunum > b.trunum)
		return true;
	return false;
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int ans = 0;
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		num[i].trunum = i;
	for (int i = 1; i <= n; i++)
		num[i].les = a[i] - a[i - 1];
	sort (num, num + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (num[i].trunum == 1)
			continue;
		if (num[i].trunum  <= ans)
			continue;
		int num_sum = 0, forlen = 1;
		int j = num[i].trunum - 1;
		while (num_sum <= m || j > 1) {
			if (num_sum + a[num[i].trunum] - a[j] <= m) {
				num_sum  += a[num[i].trunum] - a[j];
				forlen++;
				j--;
			} else
				break;
		}
		if (forlen > ans)
			ans = forlen;
	}
	cout << ans;
	return 0;
}
