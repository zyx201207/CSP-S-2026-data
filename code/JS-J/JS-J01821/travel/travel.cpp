# include <bits/stdc++.h>
# define int long long
using namespace std;
string a,b;
int n,m,x,y,u,v;
signed main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> a >> m >> b;
	x = (a[0] - '0') * 10 + (a[1] - '0');
	y = (b[0] - '0') * 10 + (b[1] - '0');
	u = a[2] - 'A' + 1; v = b[2] - 'A' + 1;
	if (n == m) {
		if (x == y) {
			if ((u <= 3 && v <= 3) || (u >= 4 && u >= 4)) {
				if (abs(u - v) == 1) cout << "1111";
				else cout << "1110";
			} else cout << "1100";
		} else cout << "1000";
	} else cout << "0000";
    return 0;
}
