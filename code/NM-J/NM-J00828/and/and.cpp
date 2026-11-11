#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], s[N] = {1}, ma, d[N], mm, maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		ma = max(ma, a[i]);
		s[i] = s[i - 1] ^ a[i];
		mm = max (mm, a[i - 1] ^ a[i]);
	}	
	if (m == 2) cout << mm;
	if (m == 1) cout << ma;
	if (m == n) cout << s[n];
	return 0;
}
