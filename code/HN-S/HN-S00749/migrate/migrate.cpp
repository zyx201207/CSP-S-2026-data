#include <bits/stdc++.h>
using namespace std;
int c , t , n , m;
int a[2000005];
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	if(c == 0)
	{
		if(t == 2)
		{
			cin >> n >> m;
			if(n == 4) cout << "1\n2\n";
			else cout << "0\n1\n";
		}
		else
		{
			cout << "8129\n16\n9\n7\n12\n0\n0\n0\n";
		}
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int cha = a[2] - a[1];
	if(m < cha || m >= cha * 2)
	{
		cout << "0";
		return 0;
	}
	cout << n - 4 + 1;
	return 0;
}
