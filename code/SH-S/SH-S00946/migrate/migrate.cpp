#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, q, p, a[500005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		q = a[n] - a[n - 1];
		p = d / q * 2;
		cout << n - p + 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
