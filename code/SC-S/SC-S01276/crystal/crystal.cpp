#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 500005;
int n, f[MAXN], ans;
long long m, a[MAXN], c[MAXN];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		long long md = m;
		int sum = 0;
		for (int j = 1; j <= n; j++){
			c[j] = abs(a[i] - a[j]);
		}
		for (int j = 1; j <= n && md; j++){
			if (c[j] <= md){
				sum++;
				md -= c[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}