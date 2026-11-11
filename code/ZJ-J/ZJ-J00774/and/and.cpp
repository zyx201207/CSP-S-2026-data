#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3 * 1e5;
int n, m, a[N], bit[N], ans;
bool vis[N];
signed main(){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)  cin >> a[i];
	for (int i = 31; i >= 0; i--){
		int cntbit = 0;
		for (int j = 1; j <= n; j++)
			if (!vis[j])
				cntbit += ((a[j] & (1 << i)) >> i);
		if (cntbit >= m){
			ans += (1 << i);
			for (int j = 1; j <= n; j++)
				if (!vis[j] && ((a[j] & (1 << i)) >> i) == 0)
					vis[j] = 1;
		}
	}
	cout << ans;
	return 0;
}
