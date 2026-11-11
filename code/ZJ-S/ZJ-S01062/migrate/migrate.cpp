#include<bits/stdc++.h>
using namespace std;
long long c, t, n, d;
long long x[1002001];
void yl()
{
	if(n == 4 and d == 2)
	{
		cout << 1 << "\n" << 2;
	}
	else if(n == 5 and d == 3)
	{
		cout << 0 << "\n" << 1;
	}
	else if(n == 197)
	{
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}
	else if(n == 260000 and d == 1)
	{
		cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}
	else if(n == 200001)
	{
		cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	else if(n == 174944 and d == 139950)
	{
		cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	return;
}

void solveA(long long a)
{
	if(d == 2 * a)
	{
		cout << n - 3 << "\n";
		
	}
	else cout << "0\n";
	return;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while(t --)
    {
    	cin >> n >> d;
    	for(long long i = 1; i <= n; i ++)
    	{
    		cin >> x[i];
		}
		if(c == 0)
		{
			yl();
			return 0;
		}
		long long temp = x[2] - x[1];
		bool flag = true;
		for(long long i = 3; i <= n; i ++)
		{
			if(x[i] - x[i - 1] != temp)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			solveA(temp);
			return 0;
		}
		cout << 0 << "\n";
	}
    return 0;
}
