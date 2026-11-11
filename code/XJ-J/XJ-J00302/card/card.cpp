#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500010], b[300010], ans[300010];

long long xxx(long long x){
	long long y = a[x], z = a[n];
	if (x >= n){
		ans[z]++;
		return 0;
	}
	if (y != z) ans[y]++;
	xxx(b[y] + 1);
	return 0;
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		xxx(i);
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}