#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;

i64 solve() {
	int n;
	i64 d;
	cin >> n >> d;
	vector<i64> x(n + 1), ans(n + 1), a1(n + 1), a2(n + 1, 0);
	vector<int> fa(n + 1);
	
	for(int i = 1, j = 1; i <= n; i ++) {
		cin >> x[i];
		while(x[i] - x[j] > d) j ++;
		fa[i] = j;
		if(j < i) {
			int c1 = fa[j];
			int c2 = j + 1 < i ? fa[j + 1] : j;
			int c3 = j + 2 < i ? fa[j + 2] : j;
			
			a1[i] = i - j;
			if(j == i - 1) a1[i] += a1[j];
			else if(fa[j + 1] > fa[j]) a1[i] += a1[j] - j + fa[j + 1];
			
			ans[i] = c3 - c2;
			if(c1 + (fa[j] != j - 1) < c2) ans[i] += ans[j];
			else if(c1 == c2 && c3 > c2) ans[i] += a1[j] - j + fa[j];
			else if(c1 < c2 && c2 < j) ans[i] += a2[c1];
		}
		
		if(i > 1) {
			int f = fa[i - 1], f2 = fa[i];
			if(f < i - 1) {
				if(f + 1 == i || f < f2 - 1) a2[i - 1] = ans[i - 1];
				else if(f < f2) a2[i - 1] = a2[f];
			}
		}
		
	}
	//i64 mx = *min_element(x.begin(), x.end());
	//for(int i = 1; i <= n; i ++) cout << x[i] - mx << "," << fa[i] << "," << a1[i] << "," << ans[i] << "\n";
	return accumulate(ans.begin(), ans.end(), 0ll);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("migrate");
	
	int testCase, T;
	cin >> testCase >> T;
	while(T --)
		cout << solve() << "\n";
}


