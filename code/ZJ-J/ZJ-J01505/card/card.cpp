#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, a[500001], tablecnt[300001], cnt[300001];
stack<int> table;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		memset(tablecnt, 0, sizeof tablecnt);
		for(int j = i;j <= n;j++) {
			if(tablecnt[a[j]] == 0) {
				tablecnt[a[j]]++;
				table.push(a[j]);
			} else {
				while(table.top() != a[j] && !table.empty()) {
					tablecnt[table.top()]--;
					table.pop();
				}
			}
		}
		while(!table.empty()) {
			cnt[table.top()]++;
			table.pop();
		}
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
}
