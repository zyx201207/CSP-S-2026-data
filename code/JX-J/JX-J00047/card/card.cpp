#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int cnt[200005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(a[j] != a[j+1]) {
				cnt[a[j]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
