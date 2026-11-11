#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	cout << a[m - 1];
	return 0;
}

//我去，这能行？
//我赌会有TLE和Wonderful Answer
//。。。
//这算瞎猫碰到死耗子了
//键盘好难用啊QAQ