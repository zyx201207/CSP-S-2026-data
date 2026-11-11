#include <bits/stdc++.h>
#define int long long
using namespace std;
int T; 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cout << rand() % 100 - 1 << '\n';
	}
	return 0;
}

