#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
vector<long long> w(500010);
vector<long long> k(510);
vector<vector<long long>> a(510, vector<long long>(500010));
vector<vector<long long>> t(510, vector<long long>(500010));
vector<pair<long long, long long>> r(100010);
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for (long long i = 1; i <= n; i ++){
		cin >> k[i];
		for(long long j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (long long i = 1; i <= q; i ++){
		cin >> r[i].first >> r[i].second;
		cout << w[r[i].first] + w[r[i].second];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
