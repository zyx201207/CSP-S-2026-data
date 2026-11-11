#include<bits/stdc++.h>
using namespace std;
int n, res, r;
long long m, a[500005], sum;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = -a[i];
	}
	sort(a + 1, a + 1 + n);
	r = 1;
	for (int i = 1; i <= n; i++){
		while (r < n && sum + a[r + 1] - a[i] <= m){
			sum += a[r + 1] - a[i];
			r++;
		}
		res = max(res, r - i + 1);
		sum -= (r - i) * (a[i + 1] - a[i]);
	//	cerr << i << " " << r << "\n";
	}
	cout << res;
	return 0;
}
