#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
const ll INF = 1e12+5;
ll n, m, mn = INF, mx, cha[N], a[N];
bool f;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out",  "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		mx += (a[n] - a[i]);
	for (int i = 2; i <= n; i++) {
		cha[i] = a[i] - a[i - 1];
		mn = min(mn, cha[i]);
		if (i > 2 && cha[i] != cha[i - 1])
			f = 1;
	}
	if (m < mn)
		cout << "1";
	else if (m == mn)
		cout << "2";
	else if (m > mx)
		cout << n;
	else {
		//A&B
		if (!f) {
			ll sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += (i *cha[n]);
				if (sum > m) {
					cout << i;
					return 0;
				}
			}
		} else {
			//ans1
			ll l = 1, r = n, ans1 = mx, ans2 = mx, ans3 = mx;
			while (ans1 > m) {
				ll js1 = a[r] - a[l], js2 = (r - l) * (a[r] - a[r - 1]);
				ll now1 = ans1 - js1, now2 = ans1 - js2;
				if (now1 <= m || now2 <= m) {
					ans1 = r - l;
					break;
				}

				else {
					if (now1 < now2)
						ans1 = now1, l++;
					else
						ans1 = now2, r--;
				}
			}
			//ans2
			l = 1, r = n;
			while (ans2 > m) {
				ll js = a[r] - a[l];
				ll now = ans2 - js;
				if (now <= m) {
					ans2 = r - l;
					break;
				} else
					ans2 = now, l++;
			}
			//ans3
			l = 1, r = n;
			while (ans3 > m) {
				ll js = (r - l) * (a[r] - a[r - 1]);
				ll now = ans3 - js;
				if (now <= m) {
					ans3 = r - l;
					break;
				} else
					ans3 = now, r--;
			}
			cout << max(max(ans1, ans2), ans3);
		}
	}
	return 0;
}