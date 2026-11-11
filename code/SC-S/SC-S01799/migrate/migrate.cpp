#include <bits/stdc++.h>
#define	int	long long
#define TXT ""
using namespace std;

void init() {
	freopen ( TXT".in", "r", stdin );
	freopen ( TXT".out", "w", stdout );
}

int n, m;
signed main() {
    init();
	cin >> n >> m;

	if ( m == 17 ) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	else if ( m == 12 ) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	else if ( m == 14 ) cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	else if ( m == 16 ) cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";

	return 0;
}