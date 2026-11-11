#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long c , t , n , d , cha , bu , sum;
long long x[N];
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> d;
		sum = 0;
		for (int i = 1 ; i <= n ; i ++)
		{
			cin >> x[i];
		}
		cha = x[2] - x[1];
		bu = d / cha;
		if (bu >= 3)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1 ; i <= n ; i ++)
		{
			sum += i / (bu + 2);
		}
		cout << sum << '\n';
	}
	return 0;
}
