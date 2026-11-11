#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], s[500005], b[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int nm = 1; nm <= n; nm++) {
		int ans = 0;
		for(int i = nm; i <= n; i++) {
			ans++;
			int p;
			s[ans] = a[i];
			bool flag = true;
			for(int j = 1; j < ans; j++) {
				if(s[j] == a[i]) {
					flag = false;
					p = j;
					break;
				}
			}
			if(flag == false) {
				for(int j = p+1; j <= ans; j++) s[j] = 0;
			} 
		}
		for(int i = 1; i <= ans; i++) {
			b[s[i]] ++;
			s[i] = 0;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	
	return 0;
}