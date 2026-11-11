#include<bits/stdc++.h>
using namespace std;
int n, m, s[300005], a[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++) {
		int o = 0, u = 1, p = n;
		for(int j = i; j < n; j ++) {
			for(int k = n; k > j; k --) {
				if(a[j] == a[k] && j < k) {
					o = k;
					p = j;
					u = 0;
					break;
				}	
			}
			if(u = 0) break;
		}
		if(o != 0) {
			for(int j = max(i, o); j <= n; j ++) {
				s[a[j]] ++;
			}
			for(int j = i; j < min(p, n); j ++) {
				s[a[j]] ++;
			}
		}
		else {
			for(int j = i; j <= n; j ++) {
				s[a[j]] ++;
			}
		}
		
	}
	for(int i = 1; i <= m; i ++) {
		cout << s[i] << " ";
	}
	return 0;
}


