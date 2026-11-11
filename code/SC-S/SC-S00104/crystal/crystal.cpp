#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	
	cin >> n >> m;
	
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int ans{};
	pair<int, long long> mem(0, 0);
	for (int i = 0; i < n - 1; i++) {
		int c = 1;
		long long t, d;
		int s = max(mem.first, i);
		t = a[s];
		d = mem.second;
	    for (int j = s + 1; j < n; j++) {
	    	d += c * (a[j] - t);
	    	if (d > m) {
	    		mem.first = j - 1;
	    		mem.second = d - c * (a[j] - t);
	    		if (j > 1) mem.second -= a[i + 1] - a[i];
	    		break;
			}
	    	t = a[j];
	    	c++;
		}
		
		
		if (c > ans) ans = c;
		if (n - ans >= n - i - 1) break;
	}

	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}