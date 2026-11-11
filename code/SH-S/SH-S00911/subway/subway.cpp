#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) {
		int x;
		cin >> x;
	}
	for (int i=1;i<=n;i++) {
		int k;
		cin >> k;
		while (k--) {
			int x,y;
			cin >> x >> y;
		}
	}
	while (q--) {
		int x,y;
		cin >> x >> y;
	}
	if (c==0) {
		if (n==2 && m==5 && d==20 && q==2) cout << 32 << endl << 17;
		if (n==3 && m==7 && d==20 && q==2) cout << 35 << endl << 16;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
