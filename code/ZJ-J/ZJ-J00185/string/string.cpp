#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n;
struct Node {
	int num;
	char c;
}a[N];
ll cnt = 0;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].num >> a[i].c;
	int l = 1, r = n;
	cnt = 0;
	while (l != r) {
		if (a[l].num < a[r].num) {
			if (a[l].c != a[r].c) cnt += a[l].num;
			a[r].num -= a[l].num;
			l++;
		} else {
			if (a[l].c != a[r].c) cnt += a[r].num;
			a[l].num -= a[r].num;
			r--;
		}
	}
	cout << cnt;
	return 0;
}

