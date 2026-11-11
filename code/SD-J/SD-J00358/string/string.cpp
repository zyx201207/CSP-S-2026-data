#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n, l, a[N];
char c[N], f[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		l += a[i];
	}
	int mid = l/2, cnt = 0, cnt2 = 1; 
	queue<char> q1;
	queue<char> q2;
	for(int i=1; i<=l; i++) {
		cnt++;
		f[i] = c[cnt2];
		if(cnt == a[cnt2]) {
			cnt = 0;
			cnt2++;
		}
	}
	int ans = 0;
	for(int i=1; i<=mid; i++) {
		if(f[i] != f[l+1-i])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
