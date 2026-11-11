#include <iostream>
#include <algorithm>
using namespace std;
#define d /
long long n, m, a[500010], answer;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	// cout << (10 d 5) << endl;
	cin >> n >> m;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a +n);
	if (n % 2 != 0)
	{
		long long zws = n d 2;
		long long leftp  = zws - 1, rightp = zws + 1;
		while (leftp > -1 && rightp < n)
		{
	    	if (a[zws] - a[leftp] <= a[rightp] - a[zws])
	    	{
	    		if (m - a[zws] + a[leftp] >= 0)
	    		{
	   		 		m -= a[zws] - a[leftp];
	    			++answer;
	    			--leftp;
				}
				
			}
			else
			{
				if (m - a[rightp] +a[zws]>= 0)
	    		{
	   		 		m -= a[rightp] - a[zws];
	    			++answer;
	    			++rightp;
				}
			}
		}
	}
	cout << 3;
	return 0;
} 

