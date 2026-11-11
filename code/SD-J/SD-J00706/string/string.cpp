#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i += 1) cin >> a[i] >> c[i];
	
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int i = 1, j = n, elsi = a[1], elsj = a[n], ans = 0;
	while (i < j)
	{
		int num = min(elsi, elsj);
		if (c[i] != c[j]) ans += num;
		elsi -= num; elsj -= num;
		if (elsi == 0)
		{
			i += 1;
			elsi = a[i];
		}
		if (elsj == 0)
		{
			j -= 1;
			elsj = a[j];
		}
	}
	
	cout << ans << endl;
	return 0;
}
