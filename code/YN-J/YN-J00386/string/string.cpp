#include <iostream>
#include <vector>
#define int long long
const int N = 200010;
int n, sum = 0, ans = 0;

struct nd {
	int num;
	char c;
} a[N], l[N], r[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].num >> a[i].c;
		sum += a[i].num;
	}
	int tmp = 0, mid = 0, dian = sum / 2, x1, x2, tmpnum, tot1 = 0, tot2 = 0;
	if (sum % 2 == 1) {
		for (int i = 1; i <= n; i++) {
			tmp += a[i].num;
			if (tmp > sum / 2) {
				mid = i;
				dian = dian - (tmp - a[i].num);
				tmpnum = a[i].num;
				break;
			}
		}
		x1 = dian, x2 = tmpnum - dian - 1;
	} else {
		for (int i = 1; i <= n; i++) {
			tmp += a[i].num;
			if (tmp >= sum / 2) {
				mid = i;
				dian = dian - (tmp - a[i].num);
				tmpnum = a[i].num;
				break;
			}
		}
		x1 = dian, x2 = tmpnum - dian;
	}
	for (int i = 1; i < mid; i++)
		l[++tot1] = {a[i].num, a[i].c};
	l[++tot1] = {x1, a[mid].c};
	for (int i = n; i > mid; i--)
		r[++tot2] = {a[i].num, a[i].c};
	r[++tot2] = {x2, a[mid].c};
	std::vector<nd>b, c;
	int i = 1, j = 1;
	while (i <= tot1 && j <= tot2) {
		if (l[i].num < r[j].num) {
			b.push_back({l[i].num, l[i].c});
			c.push_back({l[i].num, r[j].c});
			r[j].num -= l[i].num;
			i++;
		} else if (l[i].num > r[j].num) {
			b.push_back({r[j].num, r[j].c});
			c.push_back({r[j].num, l[i].c});
			l[i].num -= r[j].num;
			j++;
		} else {
			b.push_back({r[j].num, r[j].c});
			c.push_back({r[j].num, l[i].c});
			i++, j++;
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (b[i].c != c[i].c)
			ans += b[i].num;
	}
	std::cout << ans;
	return 0;
}
