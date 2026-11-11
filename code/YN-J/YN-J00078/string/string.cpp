#include <iostream>
using namespace std;
char c[1000000005];
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long start = 1;
	for(long long i = 1;i <= n;i++)
	{
        long long x;
		cin>>x;
		char y;
		cin>>y;
		for(long long j = start;j <= start + x;j++)
		{
			c[j] = y;
		}
		start = start + x;
	}
	long long ans = 0;
	if((start - 1) % 2 != 0)
	{
	    for(long long i = 1;i < start / 2;i++)
	    {
		    if(c[i] != c[start - i])
	        {
			    ans++;
		    }
	    }
	}
	else
	{
		for(long long i = 1;i <= start / 2;i++)
		{
			if(c[i] != c[start - i])
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
