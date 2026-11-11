#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
const int maxn = 5e3 + 10;
int n, m, a[maxn], ans[maxn], table[maxn];
int vis[maxn], t[5010];
bool flag = 1;
void solve(int l) {
	int len = 0;
	for(int i = l; i <= n; i ++) {
		if(!vis[a[i]]) {
			len ++;
			table[len] = a[i];
			vis[a[i]] = 1;
		}
		else {
			int nowlen = 0;
			for(int idx = 1; idx <= len; idx ++) {
				if(table[idx] == a[i]) {
					nowlen = idx;
					break;
				}
			}
			for(int j = nowlen + 1; j <= len; j ++) {
				if(table[j] != a[i]) {
					vis[table[j]] = 0;
				}
			}
			len = nowlen;
		}
	}
//	cout << "round" << l << "\n";
	for(int i = 1; i <= len; i ++) {
		ans[table[i]] ++;
//		cout << table[i] << "\n";
	}
}

int main() {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 2; i <= n; i ++) {
		if(a[i] < a[i - 1]) {
			flag = 0;
			break;
		}
	}
	
	if(n <= 500 && m <= 300) {
		for(int i = 1; i <= n; i ++) {
			memset(vis, 0, sizeof vis);
			memset(table, -1, sizeof table);
			solve(i);
		}
		
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	}
	else if(flag) {
		for(int i = 1; i <= n; i ++) {
			memset(t, 0, sizeof t);
			for(int j = i; j <= n; j ++) {
				t[a[j]] ++;
			}
			for(int j = 1; j <= m; j ++) {
				if(t[j]) {
					ans[j] ++;
				}
			}
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
	}
	
	return 0;
} 
