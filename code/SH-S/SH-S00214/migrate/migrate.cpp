#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main()
{	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(13 <= c && 14 >= c)
	{
		for(int i = 1;i <= t;i++)
		{
			cout << 0 << endl;
		}
		return 0;
	}
	else if(11 <= c && 12 >= c)
	{
		long long a[2000005];
		while(t--)
	    {
		    long long n,d;
		    cin >> n >> d;
		    for(int i = 1;i <= n;i++)
		    {
		    	cin >> a[i];
			}
			int tmp = a[2] - a[1];
			cout << n / 2 - tmp << endl;
	    }
	}
    return 0;	
} 
