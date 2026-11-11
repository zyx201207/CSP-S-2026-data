#include <bits/stdc++.h>
using namespace std;

bool s[100005] = {0};
long long a[100005], v[10005], w[100005];    //牌面，第一次在哪里，总共有几张

int main() {
	freopen("card6.in", "r", stdin);
	freopen("card6.out", "w", stdout);
	long long n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {    //轮次
//		cout << "第" << i << "轮：" << endl; 
		for (int j = i; j <= n; j++) {    //出牌
			if (s[a[j]]) {    //出过了
//				cout << a[j] << "出过了，位置为" << v[a[j]] << endl;
				for (int k = v[a[j]]; k < j; k++) {
					s[a[k]] = 0;    //从重复的开始减
//					cout << a[k] << endl;
				}
//				cout << "s[a[i]]：" << s[a[j]] << endl;
			}
			s[a[j]] = 1;    //牌面为a[i]的牌数+1
			v[a[j]] = j;    //记录牌面为a[i]的位置
//			cout << "出第" << j << "张，牌面为" << a[j] << endl;
		}
//		cout << "剩了：";
		for (int k = 1; k <= m; k++) {
			if (s[k]) {
//				cout << k << ' ';
				w[k]++;
			}
			s[k] = 0;
		}
//		cout << endl;
	}
	for (int i = 1; i <= m; i++) cout << w[i] << ' ';
	return 0;
}
