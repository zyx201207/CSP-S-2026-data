#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
long long n, m, maxm = 0;
const long long x = 4294967295;
vector<long long> a;
string s;

long long dfs(long long cnt, long long sum, long long y) {
	long long maxx = 0;
	sum = sum & a[y];
	if (cnt == 0) {
		return sum;
	}
	for (int i = y + 1; i <= n; i++) {
		maxx = max(maxx, dfs(cnt - 1, sum, i));
	}
	return maxx;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n + 1, 0);
	sort(a.begin(), a.end());
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		maxm = max(maxm, dfs(m - 1, x, i));
	}
	cout << maxm;
	return 0;
}