#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, m;
int a[N];
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	if(m == 1){
		int maxn = -1;
		for(int i = 1; i <= n; i ++)
			if(a[i] > maxn) maxn = a[i];
		cout << maxn << endl;
	}
	else if(m == 2){
		int maxn = -1, ans;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n, j != i; j ++){
				ans = a[i] & a[j];
				if(ans > maxn) maxn = ans;
			}
		}
		cout << maxn << endl;
	}
	else if(m == n){
		int ans = pow(2, 21) - 1;
		for(int i = 1; i <= n; i ++)
			ans &= a[i];
		cout << ans << endl;
	}
	else if(m == n - 1){
		int maxn = -1, ans = pow(2, 21) - 1;
		for(int i = 1; i <= n; i ++){
			ans = pow(2, 21) - 1;
			for(int j = 1; j <= n; j ++){
				if(j == i) continue;
				ans &= a[j];
			}
			if(ans > maxn) maxn = ans;
		}
		cout << maxn << endl;
	}
	else{
		sort(a + 1, a + n + 1, greater<int>());
		cout << a[m] << endl;
	}
	
	return 0;
}
