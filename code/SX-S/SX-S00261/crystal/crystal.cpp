#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500001];
long long ans = 0;//答案
long long temp = 0;//临时存储，用来存储所要的能量好和m比对（哦不不不不不，这个temp无疑是好用的）
long long bl;//大板栗
long long hc;//大红肠

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a + 1, a + n + 1);//排序 方便暴力
	a[0] = 0;

	for (long long l = 1; l <= n; l++) {
		for (long long i = l + 1; i <= n; i++) {
			bl = i - l;
			hc = a[i] - a[i - 1];
			temp += hc * bl;

			//cout << temp << endl; //调试,需删除

			if (temp > m) {
				ans = max(ans, i - l);//比较答案，选出更大的一个答案（不用大板栗，因为大板栗被吃掉了）
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
//这道题的特殊样例无疑是有用的
//拼尽全力无法战胜