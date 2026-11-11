#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int n,m,ans;
int a[N];

int main() {
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1) {
		for(int i = 1; i <= n; i++) ans = max(ans,a[i]);
		cout << ans;
		return 0;
	}
	ans = INT_MAX;
	if(m == n) {
		for(int i = 1; i <= n; i++) ans = ans & a[i];
		cout << ans;
	}
	return 0;
}
