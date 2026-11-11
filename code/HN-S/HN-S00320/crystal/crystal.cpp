#include <bits/stdc++.h>
// fun ugly chicken kill cars can't find
// I AK IOI
// kkksc03 is sb
// I am sb
// Daniel_Chou_HN is sb
// fuck chen_zhe
using namespace std;
int a[500005];
bool vis[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int d = a[2] - a[1];
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(sum + d * cnt > m) {
			break;
		}
		sum += d * cnt;
		cnt++;
	}
	cout << cnt;
	return 0;
}
