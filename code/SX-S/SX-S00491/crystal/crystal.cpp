#include <bits/stdc++.h>
#define ll long long
#define mp make_pair()
using namespace std;
ll a[500005];

//  ___  ___          _____  |  /     _____  ____
//   |   |     |   |  |      |/       |
//   |   ---   |   |  |      |\       |
//   |	 |     |   |  |      | \      |
//  ---  |     -----  _____  |  \     _____
int main() {
	int n, m, i, j, k, ans = 0, cnt;
	ll num, b, c, m1;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> b;
		a[i] = b;
	}

	sort(a, a + n);

	for (i = n - 1; i >= ans; i--) {
		m1 = m;
		/*if (i == a[n / 2] or i == a[n / 2] + 1) {
			cnt = 1;
		} else {
			cnt = 0;
		}*/
		cnt = 1;
		num = a[i];
		j = i;
		while (m1 >= 0) {
			b = 1000000000000000, c = 100000000000000;
			if (j - 1 >= 0) {
				b = abs(num - a[j - 1]);
			}
			/*if (k + 1 < n) {
				c = abs(a[k + 1] - num);
			}*/
			//cout << b << " " << c << "num" << num << endl;
			if (m1 - b >= 0) {
				cnt++;
				ans = max(cnt, ans);
				j -= 1;
				m1 -= b;
			}
//				} else if (c <= b and m1 - c >= 0) {
//					cnt++;
//					ans = max(cnt, ans);
//					k += 1;
//					m1 -= c;
			else {
				break;
			}

		}
	}
//
//	m1 = m;
//	cnt = 1;
//	num = a[n - 1];
//	j = n - 1;
//
//	while (m1 >= 0) {
//		b = 1000000000000000;
//		if (j - 1 >= 0) {
//			b = abs(num - a[j - 1]);
//		}
//
//		if (m1 - b >= 0) {
//			cnt++;
//			ans = max(cnt, ans);
//			j -= 1;
//			m1 -= b;
//		} else {
//			break;
//		}
//	}
//
//	for (i = n - 2; i > ans; i--) {
//		cnt--;
//		m1 += cnt * (a[i + 1] - a[i]);
//		j = n - cnt - 1;
//		num = a[i];
//		while (m1 >= 0) {
//			b = 1000000000000000;
//			if (j - 1 >= 0) {
//				b = abs(num - a[j - 1]);
//			}
//
//			if (m1 - b >= 0) {
//				cnt++;
//				ans = max(cnt, ans);
//				j -= 1;
//				m1 -= b;
//			} else {
//				break;
//			}
//		}
//
////	} else {
////		cnt = 1, m1 = m;
////		num = a[int(n / 2)];
////		j = n / 2, k = n / 2;
////		while (m1 >= 0) {
////			if (j - 1 >= 0) {
////				b = num - a[j - 1];
////			}
//////			if (k + 1 < n) {
//////				c = a[k + 1] - num;
//////			}
////			if (m1 - b >= 0 and b <= c) {
////				j--;
////				cnt++;
////				ans = max(cnt, ans);
////				m1 -= b;
////				b = 10000000000000;
//////			} else if (m1 - c >= 0 and c < b) {
//////				k++;
//////				cnt++;
//////				ans = max(cnt, ans);
//////				m1 -= c;
//////				c = 10000000000000;
////			} else {
////				break;
////			}
////		}
////	}
//		/*for (i = 0; i < n; i++) {
//			cnt = 1, m1 = m;
//			num = a[i];
//			j = i, k = i;
//			while (m1 >= 0) {
//				if (j - 1 >= 0) {
//					b = num - a[j - 1];
//				}
//				if (k + 1 < n) {
//					c = a[k + 1] - num;
//				}
//				if (m1 - b >= 0 and b <= c) {
//					j--;
//					cnt++;
//					ans = max(cnt, ans);
//					m1 -= b;
//					b = 10000000000000;
//				} else if (m1 - c >= 0 and c < b) {
//					k++;
//					cnt++;
//					ans = max(cnt, ans);
//					m1 -= c;
//					c = 10000000000000;
//				} else {
//					break;
//				}
//			}
//
//		}*/
//	}
	cout << ans << endl;
	return 0;
}
