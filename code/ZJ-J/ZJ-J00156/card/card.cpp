#include<bits/stdc++.h>
using namespace std;
long long n, m, rp;
long long a[500010];
long long cnt[300010];
long long v[500010], id = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	rp++;
	cin >> n >> m;
	rp++;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	rp++;
	for(long long i = 1; i <= n; i++) {
		for(long long j = i; j <= n; j++) {
			long long x = a[j];
			id++;
			v[id] = x;
			for(long long i = 1; i <= id; i++) {
				if(v[i] == x) {
					id = i;
					break;
				}
			}
		}
		rp++;
		for(long long i = 1; i <= id; i++) {
			cnt[v[i]]++;
			v[i] = 0;
		}
	}
	rp++;
	for(long long i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}