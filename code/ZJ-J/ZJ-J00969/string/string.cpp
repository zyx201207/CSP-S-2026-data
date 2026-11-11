#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
LL n, l, ans;
char str[maxn];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; ++j)
		{
			str[++l] = c;
		}
	}
	for (int i = 1, j = l; i <= j; ++i, --j)
	{
		if (str[i] != str[j])
		{
			++ans;
		}
	}
	cout << ans;
	return 0;
}
// 1~12, 17~18, tot 14/25 56pts (maybe...
/* ???
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, l, ans, mid;
int lf, rf;

struct node {
	int len;
	char c;
}_482[maxn], str[maxn];

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	cin >> n;
	mid = n / 2;
	lf = mid + 1, rf = mid - 1;
	for (int i = 1; i <= n; ++i) {
		int a;
		char c;
		cin >> a >> c;
		l += a;
		_482[i] = {a, c};
	}
	int sum = 0;
	for (int i = 1, nowl = 0, flag = 0; i <= n; ++i) {
		int a = _482[i].len;
		char c = _482[i].c;
		nowl += a;
		if (nowl >= (l + 1) / 2 && !flag) {
			flag = 1;
			if ((l + 1) / 2 - 1 - (nowl - a)) {
				str[++sum] = {(l + 1) / 2 - 1 - (nowl - a), c};
			}
			str[++sum] = {1, '0'};
			mid = sum;
			lf = mid, rf = mid;
			if (nowl - (l + 1) / 2) {
				str[++sum] = {nowl - (l + 1) / 2, c};
			}
		} else {
			str[++sum] = {a, c};
		}
	}
	int i = 1, j = sum;
	int _i = str[i].len;
	int _j = str[j].len;
	for (;;) {
		if (i == lf && j == rf) {
			break;
		}
		if (str[i].c == str[j].c) {
			if (str[i].len >= str[j].len) {
				str[i].len -= str[j].len;
				str[j].len = 0;
				_j += str[--j].len;
			} else {
				str[j].len -= str[i].len;
				str[i].len = 0;
				_i += str[++i].len;
			}
		} else {
			if (i < lf && j > rf) {
				if (_i <= _j) {
					ans += str[i].len;
					_i += str[++i].len;
				} else {
					ans += str[j].len;
					_j += str[--j].len;
				}
			} else {
				if (i == lf) {
					ans += str[j].len;
					_j += str[--j].len;
				} else {
					ans += str[i].len;
					_i += str[++i].len;
				}
			}
		}
	}
	cout << ans / 2;
	return 0;
}
*/
