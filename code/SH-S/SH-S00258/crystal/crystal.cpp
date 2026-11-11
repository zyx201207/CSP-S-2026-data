#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

int n;
long long m;

bool spjA = true, spjB = true;

bool check(vector<long long> &a, vector<long long> &diff, int x) {
	// check if merging towards x exceeds m
	// \sum{i=1}{x-1}{i * diff[i]} <= m
	long long res = 0;
	for (int i = 1; i <= x; ++i) {
		res += i * diff[i];
	}
	if (res <= m) return true;
	else return false;
} // O(n)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		
		if (a[i] != i + 1) spjA = false;
		if (i >= 2) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) spjB = false;
		}
	}
	
	sort(a.begin(), a.end()); // O(nlog(n))
	
	if (n <= 10000) {
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			int tmp = 0;
			int j;
			for (j = i; j >= 0; --j) {
				if (tmp + (a[i] - a[j]) <= m) {
					tmp += (a[i] - a[j]);
				}
				else {
					break;
				}
			}
			
			ans = max(ans, (i - j + 1));
		}
	
		cout << ans - 1 << "\n";
		return 0;
	}
	
	if (spjA) {
		int x = ceil(float(sqrt(1 + 8*m) - 1.0) / 2.0);
		cout << x;
		return 0; 
	}
	if (spjB) {
		int d = a[n - 1] - a[n - 2];
		int x = ceil(float(sqrt(1 + 8*m/d) - 1.0) / 2.0);
		cout << x;
		return 0;
	}
	
	vector<long long> diff(n);
	for (int i = 1; i < n; ++i) {
		diff[i] = a[i] - a[i - 1];
	}
	
	// binary search
	int lo = 1, hi = n - 1;
	while (lo < hi) {
		int mid = (lo - hi) / 2 + hi;
		if (check(a, diff, mid)) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	
	cout << lo + 1 << "\n";
	return 0;
}
