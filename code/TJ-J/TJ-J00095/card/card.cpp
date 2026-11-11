#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i];
		if(c[b[i]]==1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=b[i]-1;j>=1;j--)
				{
					if(b[j]==b[i])
				}
			}
		}
		c[a[i]]=1;
		
	}
	return 0;
}
