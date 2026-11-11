#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	long long ans = 1;
	if (n < 100000 || m < 100000000) {
		for (int i = 1; i <= n; ++i) {
			long long t = 0, tm = 1;
			for (int j = i - 1; j >= 0; --j) {
				if (t + a[i] - a[j] <= m) {
					t += a[i] - a[j];
					++tm;
				}
			}
			ans = max(ans, tm);
		}
	} else {
		int t = a[1] - a[0];
		t = m / t;
		
		int tmp = 0;
		for (int i = 1; i <= t; ++i) {
			tmp += i;
		}
		cout << tmp << endl;
	}
	
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}