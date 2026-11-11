#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long m;
long long n;

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	//特殊样例AB
	bool flag = true;
	long long cha = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (cha != (a[i] - a[i - 1]))
			flag = false;
	}
	if (flag) {
		long long jieguo = 0;
		for (int i = n; i >= 1; i--) {
			m = m - (a[n] - a[i]);
			if (m >= 0)
				jieguo++;
			else
				break;
		}
		cout << jieguo << endl;
		return 0;
	}
	//从最大的开始
	long long n1 = n;
	long long maxx = -1;
	while (n1--) {
		long long m1 = m;
		long long jieguo1 = 0;
		for (int i = n1; i >= 1; i--) {
			m1 = m1 - (a[n1] - a[i]);
			if (m1 >= 0)
				jieguo1++;
			else
				break;
		}
		maxx = max(maxx, jieguo1);
	}
	cout << maxx << endl;
	return 0;
}