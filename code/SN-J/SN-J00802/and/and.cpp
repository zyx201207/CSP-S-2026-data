//SN-J00802 王欣甜 西安市铁一中学
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
int flag[maxn];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		flag[i] = 1;
	}
	int ans = 0;
	for(int i = 29; i >= 0; i--) {
		int res = 0;
		for(int j = 1; j <= n; j++)if(flag[j]) {
			if(a[j] >> i & 1) {
				res++;
			}
		}
		if(res < m)continue;
		for(int j = 1; j <= n; j++)if((a[j] >> i & 1) != 1) {
			flag[j] = 0;
		}
		ans |= (1 << i);
	}
	cout << ans << endl;
}
