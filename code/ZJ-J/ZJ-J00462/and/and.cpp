#include<bits/stdc++.h>
using namespace std;
int n, m, x[200010], c[40], ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(x[i] >= (1 << 30))
			c[1]++;
	}
	for(int i = 1; i <= 31; i++) {
		if(c[i] >= m)
			ans += (1 << (31 - i));
		if(i == 31)
			break;
		if(c[i] < m)
			for(int j = 1; j <= n; j++)
				if((x[j] & (1 << (31 - i))) == (1 << (31 - i)))
					x[j] -= (1 << (31 - i));
		for(int j = 1; j <= n; j++)
			if(x[j] >= ans + (1 << (30 - i)))
				c[i + 1]++;
	}
	cout << ans;
	return 0;
}

