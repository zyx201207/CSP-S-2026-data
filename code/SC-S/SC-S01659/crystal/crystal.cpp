#include<bits/stdc++.h>
#define LoveFurina ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F(x, l, r) for(int x = l; x <= r; ++x)
#define B(x, r, l) for(int x = r; x >= l; --x)
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 5e5 + 10;

int n;
ll m, a[N]; 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	LoveFurina;
	
	cin >> n >> m;
	F (i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	int ans = 0, l = 1; ll sum = 0;
	F (r, 1, n) {
		sum += a[r];
		while (a[r] * (r - l + 1) - sum > m) sum -= a[l++];
		ans = max(ans, r - l + 1); 
	}
	cout << ans;
	
return 0;
}
// 关注 luogu @DanseSolo 谢谢 awa 