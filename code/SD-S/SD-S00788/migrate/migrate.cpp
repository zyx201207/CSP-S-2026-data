#include <bits/stdc++.h>
using namespace std;
long long a[2000005],s,cnt,r;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		cnt = 0;
		long long pos = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i = n;i>=1;i--)
		{
			if(a[i] - a[i-1] > d)
			{
				pos  = i;
			}
		}
		for(int i = 1;i<=n-pos;i++)
		{
			for(int j = 1;j<=i;j++)
			{
				long long s = a[i]-a[j];
				if(s % d!=0)
				{
					r = s/d+1;
					if(s%r != 0)
					{
						cnt++;
					}
				}
				else
				{
					continue;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
