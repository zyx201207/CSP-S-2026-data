#include <bits\stdc++.h>
using namespace std;
long long n,m,a[1000000000005],ans=0,num=1;

int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >>a[i];
	}
	if (m <=n){
	    for (int i = 1; i <= n;i++)
	    {
	        num=1;
	   	    for (int j = i+1; j <= n; j++)
	        {
		        if (a[i] + num == a[j])
		        {
			        ans++;
			        m -= num;
		        }
		        num++;
	        }
        }
    }
	else if(m > n)
	{
		for (int i = 1; i <= n;i++)
	    {
		    num=1;
	        for (int j = i+1; j <= m; j++)
		    {
		        if (a[i] + num == a[j])
		        {
		    	    ans++;
		    	    m -= num;
		        }
		        num++;
	        }
	    }
	}
	if (ans != 0)
	{
		cout <<ans+1;
	}
	else
	{
		cout <<ans;
	}
	return 0;
}
