#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long card[n + 1] = {0};
	long long ans[m + 1] = {0};
	long long tmp[n + 1];
	for(long long i = 1; i <= n; i ++) {
		cin >> card[i];
	}
	for(long long i = 1; i <= n; i ++) {
		memset(tmp, -1, sizeof tmp);
		for(long long j = i; j <= n; j ++) {
			long long p = j;
			for(long long k = i; k < j; k ++) {
				if(tmp[k] == card[j]) {
					p = k;
					break;
				}
			}
			for(long long k = p; k < j; k ++) {
				tmp[k] = -1;
			}
			tmp[j] = card[j];
		}
		for(long long j = i; j <= n; j ++) {
			if(tmp[j] > 0) ans[tmp[j]] ++;
		}
	}
	cout << ans[1];
	for(long long i = 2; i <= m; i ++) cout << " " << ans[i];
	return 0;
}















