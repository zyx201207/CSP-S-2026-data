#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500010];
long long ans = 0, cnt = 0, maxn = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans = 0, cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] < a[i]) {
				ans += a[i] - a[j];
				if (ans <= m) {
					cnt++;
				}
			}
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn + 1 << endl;
	return 0;
}
/*
最后剩25分钟才做完
真的蒟蒻呀
我竟然还能过样例
极限！！！
还是不用long long了吧
怕超时
666
别阴我(T _ T* )
算
赌一把
long long 走起
*/