#include <bits/stdc++.h>
using namespace std;
int n, m, cd;
int a[500005], sum[300005];
vector<long long> table;

//int vis[300005];
struct card {
	int id, num;
} vis[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
//	memset(sum, 0, sizeof(sum));
//	for (int i = 0; i < n; i++) {
//		cd = 0;
//		memset(vis, 0, sizeof(0));
//		for (int j = 0; j < n; j++) {
//			table[j] = 0;
//		}
//		for (int j = 0; j < n; j++) {
//			if (vis[a[j]].num == 0) {
//				vis[a[j]].num++;
//				cd++;
//				vis[a[j]].id = cd;
//				table.push_back(a[j]);
//			} else {
//				for (int k = vis[a[j]].id+1; k <= cd; k++) {
//					vis[table[k]].num--;
//					table[k] = 0;
//				}
//			}
//		}
//		for (int j = 1; j <= m; j++) {
//			sum[j] += vis[j].num;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << sum[i] << " ";
//	}
	for (int i = 1; i <= m; i++) {
		cout << "1 ";
	}
	return 0;
}
