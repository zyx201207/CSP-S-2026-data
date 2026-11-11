// JS-S01191
// migrate.cpp
// version 1

#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, ans;
int a[2000005];
vector<pair<int, int> > groups;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--){
		ans = 0;
		groups.resize(0);
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		int st = 1;
		for (int i = 2; i <= n; ++i){
			if (a[i] - a[i - 1] > d){
				if (i - st > 2) groups.push_back({st, i - 1});
				st = i;
			}
		}
		if (n + 1 - st > 2) groups.push_back({st, n});
		// cout << groups.size() << "\n";
		for (auto x : groups){
			int first = x.first, second = x.second;
			for (int i = first; i <= second - 2; ++i){
				for (int j = i + 2; j <= second; ++j){
					// cout << i << " " << j << "\n";
					int cnt = 0;
					for (int k = i + 1; k <= j - 1; ++k){
						if (a[k] - a[i] <= d && a[j] - a[k] <= d && a[j] - a[i] > d){
							++cnt;
						}
					}
					if (cnt == 2){
						// cout << i << " " << j << "\n";
						++ans;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
