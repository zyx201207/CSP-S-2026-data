#include <bits/stdc++.h>
using namespace std;
const int N=2e5+12;
int inf=1073741824;
int n,m;
long long ans;
int b[50];
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int c=a[i];
		for(int j=0;j<=31;j++)
		{
			if((c&1)==1)
			{
				b[j]++;
			}
			c=c >> 1;
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(b[i]>=m)
		{
			ans+=inf;
			for(int j=1;j<=n;j++)
			{
				if((a[j] & inf)==0)
				{
					for(int k=0;k<=31;k++)
					{
						if((a[j]&1)==1)
						{
							b[k]--;
						}
						a[j]=a[j] >> 1;
					}
				}
			}
		}
		inf=inf >> 1;
	}
	cout<<ans;
	return 0;
}
