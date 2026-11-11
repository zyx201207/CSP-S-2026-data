#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans = INT_MAX;
int f[20];
bool bin[200005][20];
void sol(int x, int p){
	int i = 0;
	while (x){
		bin[p][i] = (x & 1);
		if (x & 1) ++f[i];
		x >>= 1;
		i++;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; ++i) sol(a[i], i);
	for (int i = 18; i >= 0; --i){
		if (f[i] >= m){
			for (int j = 1, k = 1; j <= n && k <= m; ++j){
				if (bin[j][i]){
					k++;
					ans &= a[j];
				}
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
