#include <bits/stdc++.h>
using namespace std;
int n, m;

struct card {
	int val;
	int pos;
} a[500005];
bool num[300005];//表示哪个点数的在场上
int ansnum[300005];

stack<card> q;//从左到右（从前到后）的桌面上的所有牌
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].pos = i;
	}
	for (int i = 1; i <= n; i++) { //每局
		queue<card> temp;//保存左边的
		memset(num, 0, sizeof(num));
		for (int j = i; j <= n; j++) { //每张牌
			if ( num[a[j].val] ) { //场上有此点数的牌
				while ( 1 ) {
					if ( q.top().val == a[j].val ) {
						q.pop();
						break;
					}
					num[q.top().val] = 0;
					q.pop();
				}
				q.push(a[j]);
				num[a[j].val] = 1;
			} else {
				num[a[j].val] = 1;
				q.push(a[j]);
			}
		}
		while ( !q.empty() ) { //统计
			ansnum[q.top().val]++;
			q.pop();
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << ansnum[i] << ' ';
	}
	return 0;
}
