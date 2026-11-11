#include <bits/stdc++.h>
using namespace std;

const int MAXL = 2e5 + 8;
int n,m;
long long a[MAXL],ans;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1 ; i <= n - m + 1 ; i++) {
		long long cnt = a[i];
		for(int j = i + 1; j < i + m ; j++) {
			cnt &= a[j];
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}
