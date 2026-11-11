#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=1,best=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i] >= best)
			{
				best = a[i];
			}
		}
		cout << best;
	}
	if(m==2)
	{
		for(int i =1;i<=n;i++)
		{
			for(int j =1;j<=m;j++)
			{
				if(a[i] and a[j] >= sum)
				{
					sum = a[i] and a[j];
				}
			}
		}
		cout << sum;
	}
}