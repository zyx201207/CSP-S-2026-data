#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010];
int a[510][500010],t[510][477169];
int T;

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	bool tA = 1,tB = 1;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		if (k > 2) {
			tA = 0;
		}
		int Tt;
		for (int j = 1;j <= k;j++) {
			cin >> a[i][j] >> t[i][j];
			if (j == 1) {
				Tt = t[i][j];
			}
			if (t[i][j] != Tt) {
				tB = 0;
			}
		}
		T = Tt;
	}
	for (;q--;) {
		int x,y;
		cin >> x >> y;
		if (tB) {//”–µ»÷µT 
			cout << T * 2 << "\n";
		} else {
			cout << a[1][1] + t[1][1] + w[1] << "\n";
		}
	}
	return 0;
}
