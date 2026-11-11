#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int j = t;j >= 1;j--)
	{
		int n,d,num = 1;
		cin >> n >> d;
		for (int i = 0;i < n;i++)
		{
			int x;
			cin >> x;
	    }
	    while(d >= 0) 
	    {
	    	num *= d;
	    	d--;
		}
		cout << num;
	}
	return 0;
}
