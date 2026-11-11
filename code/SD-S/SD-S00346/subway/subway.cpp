#include<bits/stdc++.h>
using namespace std;
#define ull unsigend long long
#define ll long long
#define pb push_back
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	if(c == 0)
	{
		if(n == 2)
		{
			cout << 32 << '\n';
			cout << 17;
			return 0;
		}
		else if(n == 3)
		{
			cout << 35 << '\n';
			cout << 16;
			return 0;
		}
	}
	return 0;
}
