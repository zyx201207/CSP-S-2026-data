#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long x=n;
	while(x--) 
	{
		for (int i=n-x;i<=n;i++)
		{
			b[a[i]]++;
			if(b[a[i]]>i)
			{
				for (int j=1;j<i;j++)
				{
					if(b[a[j]]>=1)
					b[a[j]]--;
				}
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << b[i] << " ";
	 } 
	return 0;
}
	
