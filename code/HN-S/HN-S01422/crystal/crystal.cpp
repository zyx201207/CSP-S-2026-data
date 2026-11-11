#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum[500005], f[500005], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++){
		int l = 1, r = i;
		while (l <= r){
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m){
				f[i] = i - mid + 1;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		ans = max(ans, f[i]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 5
//1 2 4 8 9 3 -> 1 2 3 4 8 9
//3
//1 1000000000 -> 500000
//mid = 1 -> 2000000000 - 1000000001 = 999999999 > 500000 -> l = mid = 1
//2 -> mid = 1 ...
