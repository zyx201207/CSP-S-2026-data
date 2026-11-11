#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, m, a[N], c[N], ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		c[i] = c[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		long long l = 1, r = i;
		while(l <= r){
			long long mid = (l + r) / 2;
			long long hf = c[i] - (c[mid - 1] + (mid - 1) * (a[i] - a[mid - 1]));
			if(hf <= m){
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		ans = max(ans, i - r);
	}
	cout << ans << "\n";
	return 0;
}
