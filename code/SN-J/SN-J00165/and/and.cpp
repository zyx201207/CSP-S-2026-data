#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long a[maxn], ans;
int wei[maxn], n, m, sum, cnt;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for (int i = 30; i >= 0; i --){
		sum = 0;
		for (int j = 1; j <= n; j ++){
			if (wei[j] != cnt) continue;
			if ((a[j] >> i) & 1 == 1) sum ++;
		}
		if (sum >= m){
			cnt ++;
			ans += (1 << i);
			for (int j = 1; j <= n; j ++){
				if ((a[j] >> i) & 1 == 1) wei[j] ++;
			}
		}
	}
	cout << ans;
	return 0;
} 
