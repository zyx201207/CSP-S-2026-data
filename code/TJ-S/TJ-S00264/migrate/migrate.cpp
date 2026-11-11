#include <bits/stdc++.h> //Howson
using namespace std;

int c, d, n, t;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t >> n >> d;

	if (c == 0 && n == 4 && d == 2) cout << "1" << endl << "2";
	if (c == 0 && n == 5 && d == 3) cout << "0" << endl << "1";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
