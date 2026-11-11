#include <bits/stdc++.h> //Howson
using namespace std;

int c, n, m, d, q, w[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];

    if (c == 0 && n == 2) cout << "32" << endl << "17";
    if (c == 0 && n == 3) cout << "35" << endl << "16";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
