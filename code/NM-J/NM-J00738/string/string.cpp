#include <cstdio>
#include <iostream>
using namespace std;

struct node {
	int b;
	char c;
	bool flg;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].b >> a[i].c;
		a[i].flg = false;
	}
	long long ans = 0;
	int s = n, e = 1;
	for (int i = 1; i <= n; i++) {
		int b = a[i].b;
		char c = a[i].c;
		if (!a[i].flg) {
			for (int j = s; j >= e; j--) {
				if (!a[j].flg) {
//					cout << "i = " << i << " j = " << j << ' ';
					if (a[j].c != c) {
						if (a[j].b < b) {
//							cout << "fenzhi3(a[j].b < b) ";
							ans += b - a[j].b;
							b -= a[j].b; // 将这段的字符修改为第一段的字符
							a[j].flg = true;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
						} else if (a[j].b == b) {
//							cout << "fenzhi2(a[j].b == b) ";
							ans += b;
							s = j - 1; // 下一轮从当前的前一个开始查找
							e = i + 1; // 到当前的下一个结束
							a[j].flg = true;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
							break; // 查找下一段字符
						} else if (a[j].b > b) {
//							cout << "fenzhi1(a[j].b > b) ";
							ans += a[j].b - b;
							a[j].b -= b;
							s = j;
							e = i + 1;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
							break; // 查找下一段字符
						}
					} else if (a[j].c == c) {
//						cout << "a[j].c == c";
						if (a[j].b < b) {
//							cout << "fenzhi3(a[j].b < b) ";
							//ans += b - a[j].b;
							b -= a[j].b; // 将这段的字符修改为第一段的字符
							a[j].flg = true;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
						} else if (a[j].b == b) {
//							cout << "fenzhi2(a[j].b == b) ";
							//ans += b;
							s = j - 1; // 下一轮从当前的前一个开始查找
							e = i + 1; // 到当前的下一个结束
							a[j].flg = true;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
							break; // 查找下一段字符
						} else if (a[j].b > b) {
//							cout << "fenzhi1(a[j].b > b) ";
							//ans += a[j].b - b;
							a[j].b -= b;
							s = j;
							e = i + 1;
//							cout << "s = " << s << " e = " << e << " ans = " << ans;
							break; // 查找下一段字符
						}
					}
//					cout << endl;
				}
			}
		}
//		cout << endl;
	}
	printf("%lld", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

