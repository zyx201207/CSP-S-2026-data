#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 5e5 + 10;
LL n, m, a[N], sum[N], ans = 0;
LL l = 1, r = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(sum, 0, sizeof sum);
	for(LL i = 1; i <= n; i++)	cin >> a[i];
	sort(a + 1, a + n + 1);
	for(LL i = 1; i <= n; i++)	sum[i] = sum[i - 1] + a[i];
//	for(LL i = 1; i <= n; i++)	cout << sum[i] << ' ';
//	cout << '\n';
	while(l <= r){
		if(((sum[r] - sum[l - 1] + m) / (r - l + 1)) >= a[r]){
			ans = max(ans, r - l + 1);
			if(r < n)
				r++;
		}
		if(((sum[r] - sum[l - 1] + m) / (r - l + 1)) < a[r] || r == n)
			l++;
	}
	cout << ans << '\n';
	return 0;
}
