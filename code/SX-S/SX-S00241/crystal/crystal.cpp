#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll  n, a[N], m, c[N];

//struct szsz {
//	vector<int> c;
//	int n;
//	szsz(int x): c(x), n(x) {}
//	int lowbit(int x) {
//		return x&(-x);
//	}
//	void add(int x, int i) {
//		while (i <= n) {
//			c[i] += x;
//			i += lowbit(i);
//		}
//		return ;
//	}
//	long long ask(int i) {
//		long long sum = 0;
//		while (i) {
//			sum += c[i];
//			i -= lowbit(i);
//		}
//		return sum;
//	}
//};

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
//	szsz A(n);
	long long ans = 0, al = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		al += a[i];
		if (al >= n)
			al -= n, ans++;
	}
	if (al >= n)
		al -= n, ans++;
//	cout << ans << "\n";
	sort(a + 1, a + 1 + n);
	int id = lower_bound(a + 1, a + n + 1, ans) - a ;
	for (int i = 1; i <= n; i++) {
		ll cz = abs(a[id] - a[i]);
//		A.add(cz, i);
		c[i] = cz;
//		cout << c[i] << " ";
	}
//	cout << "\n";
	int li = id, r = id;
	ll sum = 0, js = 1;
//	cout << id;
	while (sum <= m   && js <= n) {

		if (c[r + 1] >= c[li - 1] && li - 1 >= 1  && c[li - 1] + sum <= m)
			li--, sum += c[li ];
		else if (c[r + 1] < c[li - 1] && r + 1 <= n && c[r + 1] + sum <= m)
			r++, sum += c[r];
		else
			break;
		if (sum <= m)
			js++;
//		cout << li << "¡¡" << r << "¡¡" << sum << "\n";
	}
	cout << js;
	return 0;
}
