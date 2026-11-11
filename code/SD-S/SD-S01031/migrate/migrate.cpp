#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, d, x[N], b[N];
struct con {
	int minn, num;
};
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	int l = 1;
	for(int i = 2; i <= n; i++) {
		while(x[i] - x[l] > d) l++;
		b[i] = l;
	}
	int cot = 0;
	for(int i = 1; i <= n; i++) {
		int l = i;
		vector<int> t(n + 1), num(n + 1);
		deque<con> q;
		q.push_back({0, 1});
		num[i] = 1;
		for(int j = i + 1; j <= n; j++) {
			while(q.size() && l < b[j]) {
				q[0].num -= num[l];
				l++;
				if(q[0].num <= 0) q.pop_front();
			}
			for(int i = 0; i < q.size(); i++) {
//				cout << q[i].minn << " " << q[i].num << "\n"; 
			}
			if(q.size() && q.front().num == 2) cot++;
			num[j] = q.size() ? q.front().num : 0, t[j] = q.front().minn + 1;
			if(q.size() && t[j] == q.back().minn) q[q.size() - 1].num += num[j];
			else q.push_back({t[j], num[j]});
//			cout << i << " " << j << " " << t[j] << " " << num[j] << "\n";
		}
	}
	cout << cot << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
