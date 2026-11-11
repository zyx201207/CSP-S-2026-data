//migrate
#include <bits/stdc+++.h>;
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	cin >>c >>t >>n;
	for (int i = 1; i <= t; i++)
	{
		cout << i + (t + c) / n << endl;
	}
	return 0;
 } 
