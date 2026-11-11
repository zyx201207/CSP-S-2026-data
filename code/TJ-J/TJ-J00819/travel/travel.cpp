#include <bits/stdc++.h>
#define ll long long
using namespace std;
string rcar,rs,xcar,xs;
bool flag;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rcar >> rs >> xcar >> xs;
	if(rcar == xcar) {
		cout << 1;
		if((rs[0] - 48) * 10 + rs[1] - 48 == (xs[0] - 48) * 10 + xs[1] - 48) cout << 1;
		else cout << 0;
		if((rs[0] - 48) * 10 + rs[1] - 48 == (xs[0] - 48) * 10 + xs[1] - 48 and ((rs[2] <= 'C' and xs[2] <= 'C') or (rs[2] >= 'D' and xs[2] >= 'D'))) {
			cout << 1;
			flag = 1;
		} else cout << 0;
		if(flag) {
			if(rs[2] == xs[2] + 1 and xs[2] + 1 != 'D' or rs[2] == xs[2] - 1 and xs[2] - 1 != 'C' or (rs[2] == 'D' and xs[2] == 'F') or (rs[2] == 'F' and xs[2] == 'D')) cout << 1;
			else cout << 0;
		} else cout << 0;
	} else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
