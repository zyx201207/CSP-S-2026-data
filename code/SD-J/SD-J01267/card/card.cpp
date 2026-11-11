#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int a[N + 5], cnt[N + 5], ct[N + 5], ans[N + 5];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool kl = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) kl = 1;
	}
	if(n <= 5000 && m <= 3000) {
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) cnt[i] = 0, ct[i] = 0;
			for(int i = k; i <= n; i++) {
				if(cnt[a[i]] == 0) cnt[a[i]] = i;
				else {
					ct[cnt[a[i]]] = i;
					for(int j = cnt[a[i]]; j <= i; j++) cnt[a[j]] = 0;
					cnt[a[i]] = i;
				}
			}
			for(int i = k; i <= n; i++) {
				while(ct[i] != 0) i = ct[i];
				ans[a[i]]++;
			}
		}
	} else {
		if(kl == 0) {
			for(int i = 1;i <= m;i++) ans[i] = n;
			for(int i = 1; i <= n; i++) {
				if(a[i - 1] != a[i] && i != 1) ans[a[i - 1]] = i - 1;
			}
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
