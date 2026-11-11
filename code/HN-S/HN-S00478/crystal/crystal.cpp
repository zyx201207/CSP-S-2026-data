#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], amaxn[1000004];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int z = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == 0) z++;
	}
	if (z == n){
		if (m < n) cout << m;
		else cout << n;
		return 0;
	}
	if (m == 0){
		for (int i = 1; i <= n; i++){
			amaxn[a[i]]++;
		}
		sort(amaxn+1,amaxn+n+1,greater<int>());
		cout << amaxn[1];
		return 0;
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		ans += a[i];
	}
	double dou = 1.0 * ans / n;
	long long maxn = -1e9, mx = -1e9; //某个数的下标 
	for (long long i = 1; i <= n; i++){
		if (a[i] > maxn && a[i] < dou){
			mx = max(mx,i);
			maxn = max(maxn,a[i]); 
		}
	}
	long long d = 0;
	while (m > 0){
		long long cs = maxn - a[mx - 1];
		m -= cs;
		d++;
	}
	cout << d;
	return 0;
}
 
