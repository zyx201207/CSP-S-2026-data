#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, a[maxn], ans;
bool ex[maxn];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int d = 29; d >= 0; d--) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!ex[i] && (a[i]>>d&1)) cnt++;
		}
		if(cnt < m) continue;
		ans |= (1 << d);
		for(int i = 1; i <= n; i++) {
			if(!ex[i] && !(a[i]>>d&1)) ex[i] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
