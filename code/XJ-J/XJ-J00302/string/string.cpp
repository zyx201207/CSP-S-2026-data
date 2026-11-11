#include<bits/stdc++.h>
using namespace std;

long long n, a[200010], ans, x, y;
char c[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	x = 1, y = n;
	while (a[x] != 0 && a[y] != 0){
		if (c[x] != c[y]){
			ans += min(a[x], a[y]);
		}
		if (a[x] < a[y]){
			a[y] -= a[x];
			a[x] = 0;
			x++;
		}
		else if (a[x] > a[y]){
			a[x] -= a[y];
			a[y] = 0;
			y--;
		}
		else{
			a[x] = 0;
			a[y] = 0;
			x++, y--;
		}
	}
	cout << ans;
	return 0;
}