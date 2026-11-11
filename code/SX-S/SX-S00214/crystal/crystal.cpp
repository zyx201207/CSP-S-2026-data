#include <bits/stdc++.h>
using namespace std;
long long int a[1000050];
long long int cnm[1000500];//差
long long int com[1000500];//等差总和

int qwe(long long int n, long long int m) {
	long long int sum = 0, i = 0;
	long long int k = n;
	while (sum <= m) {
		sum += k;
		i++;
		k += n;
		com[i] = sum;
	}
	i--;
	return i;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long int n, m, answer = 0, term = 0;
	cin >> n >> m;
	cin >> a[1];
	com[1] = a[1];
	bool flag = true;
	for (long long int i = 2; i <= n; i++) {
		cin >> a[i];
		cnm[i] = a[i] - a[i - 1];
		if (cnm[i] != cnm[i - 1] && i >= 3)
			flag = false;
	}
	//上半部分：判断是否等差数列与输入（真确）
	if (flag) {
		//b指差值多少；c指一半分多少
		long long int b = cnm[2];
		long long int c = m / 2;
		if (n % 2 == 1) {
			long long int po = qwe(b, c);
			if ((m - com[po] * 2) >= com[po + 1])
				answer++;
			answer += (po * 2);
			answer++;
		} else {
			if (c >= b) {
				answer += 2;
				c -= b;
			} else {
				if (m >= b) {
					cout << "1";
					return 0;
				} else {
					cout << "0";
					return 0;
				}
			}
			long long int po = qwe(b, c);
			if ((m - com[po] * 2) >= com[po + 1])
				answer++;
			answer += (po * 2);
		}
	} else {
		sort(a + 1, a + n + 1);
		//不是等差数列，一个一个尝试
		for (long long int i = 1; i <= n; i++) { //i指所有变到第一个
			long long int l = i, r = i, sum = 0;
			while (true) {
				long long int v;
				if (l = 1) {
					v = 1000000000;
				} else {
					v = a[l] - a[l - 1];
				}
				long long int v2;
				if (r == n) {
					r = 1000000000;
				} else {
					v2 = a[r + 1] - a[r];
				}
				if (v > v2) {
					if (m >= v2 && r < n) {
						r++;
						m -= v2;
						sum++;
					} else {
						break;
					}
				} else {
					if (m >= v && l > 1) {
						l--;
						m -= v;
						sum++;
					} else {
						break;
					}
				}
			}
			sum++;
			answer = max(sum, answer);
		}
	}
	cout << min(answer, n);
	return 0;
}