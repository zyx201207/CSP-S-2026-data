# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 2e5 + 5;
int n,m,ans,a[N]; bool idx[N][35];
vector <int> nums,v;
void bit_2 (int u) {
	int x = a[u],y = 0;
	while (x > 0) idx[u][y ++] = x % 2,x /= 2;
	return ;
}
void solve (int u) {
	v.clear();
	for (int i : nums) {
		if (idx[i][u]) v.push_back(i);
	}
	int len = v.size();
	if (len < m) return ;
	nums.clear();
	for (int i : v) nums.push_back(i);
	return ;
}
signed main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i],nums.push_back(i);
	for (int i = 1;i <= n;i++) bit_2(i);
	for (int i = 34;i >= 0;i--) solve(i);
	ans = a[nums[0]];
	for (int i = 0;i <= m - 1;i++) ans = ans & a[nums[i]];
	cout << ans;
    return 0;
}
