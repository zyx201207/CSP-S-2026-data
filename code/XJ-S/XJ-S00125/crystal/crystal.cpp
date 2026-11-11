#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5; 
int a[N], ans[N];
int n, m, maxn = -1e18;
int solve(int x){
	int l = 0, r = x + 1;
	while ( l < r - 1){
		int mid = (r + l) / 2;
		int tot = ans[x] - ans[mid - 1] - (mid - 1) * (a[x] - a[mid - 1]);
		if (tot <= m) r = mid;
		else l = mid;
	}
	return x - r + 1;
}
signed main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> m;
	for (int i = 1;i <= n; i ++)
		cin >> a[i];

	sort (a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++)
		ans[i] = (i - 1) * (a[i] - a[i - 1]) + ans[i - 1];
	
	for (int i = 1; i <= n; i ++){
		while (a[i] == a[i + 1] && i <= n) i ++;
		maxn = max(maxn, solve(i));
	}
		
	cout << maxn;
return 0;
} 
