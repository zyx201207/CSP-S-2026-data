#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node {
	ll num, cnt, sum1;
} a[200005];
ll n, m, ans;
bool cmp(node x, node y) {
	if (x.cnt != y.cnt) return x.cnt > y.cnt;
	if (x.sum1 != y.sum1) return x.sum1 < y.sum1;
	return x.num > y.num;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++) {
		cin >> a[i].num;
		ll tmp = a[i].num;
		for (int r = 1;tmp;r++) {
			if (tmp % 2) {
				a[i].cnt++;
				a[i].sum1 += r;
			}
			tmp /= 2;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].num;
	for (ll i = 2;i <= m;i++)
		ans = ans & a[i].num;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}