#include <bits/stdc++.h>
using namespace std;

long long a[200005];
long long f[200005];
long long s[200005];
long long n, W;
long long ans = -1;
int main (){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> W;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++){
		f[0] = a[k];
		for (int i = 1; i <= n; i++){
			for (int j = W; j >= 0; j--){
				f[j] = max(f[j], f[j - 1] & a[i]);
			}
		}
		ans = max (ans, f[W]);
	}
	
	cout << ans << endl;
	return 0;
}
