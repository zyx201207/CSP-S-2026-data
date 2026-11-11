#include <bits/stdc++.h> 
using namespace std;
int c,t,n,d,a[10000005],sum[10000005],k,p;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i];
		}
	} 
	for(int i = 1;i <= t;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			sum[j] = a[j + 1] - a[j];
		    if(sum[j] > d)
		    {
			    break;
		    }
		    k++;
		}
	}
	for(int i = 1;i <= t;i++)
	{
		p = 0;
		for(int i = 1;i <= k;i += d)
		{
			for(int j = i;j <= k;j += d)
            {
            	double fx = a[i] - a[j];
    	        if(a[i] - a[j] >= 0 && (a[j] - 1) % d != 0 && fx / d == 2)
    	        {
    	            p++;
			    }
	        }
		}
	    cout << p << endl;
	}
	return 0;
}
