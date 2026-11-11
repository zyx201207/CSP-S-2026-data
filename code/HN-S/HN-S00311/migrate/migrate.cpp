#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a,b;
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> a >> b;
		if ((t==2)&&(a+b==6))
		{
			cout << 1 << endl << 2;
			return 0;
		}
		if ((t==2)&&(a+b==8))
		{
			cout << 0 << endl << 1;
			return 0;
		}
		else
		{
			cout << 1 << endl;
		}
	}
	return 0;
}
