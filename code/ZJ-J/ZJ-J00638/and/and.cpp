#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], f[200005], z[31][200005], x, y;
long long dd(){
	long long ans = 0;
	for (int  i = 30 ; i >= 1; i--){
		if(f[i] == m) {
			if (f[i] == m) {
				ans = a[z[i][1]];
				for (int j = 2; j <= m; j++)
					ans = ans&a[z[i][j]];
				return ans;
			}
		}
	}
}
int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n; i++) {
		x = y = 0;
		cin >> a[i];
		long long hp =a[i];
		while (hp != 0) {
			if (hp % 2 == 1)f[++x] += 1, z[x][++y] = i;
			hp/= 2;
		}
	}
	sort(a+1, a+n+1);
	if (m == 1){
		cout << a[n];
		return 0;
	}
		
	
	cout << dd();
	return 0;
}
