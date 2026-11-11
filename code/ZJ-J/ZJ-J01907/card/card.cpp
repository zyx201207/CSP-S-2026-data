#include<bits/stdc++.h>
#define F10 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int s[500005];
int d[500005];
int main()
{
	F10
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		std::cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		int a[500005];
		int l=0;
		for(int j=i;j<n;j++)
		{
			l++;
			for(int i=0;i<l;i++)
			{
				if(a[i]==s[j])
				{
					while(l>i)
					{
						a[l-1]=0;
						l--;
					}
				}
			}
			a[l]=s[j];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<=l;j++)
			{
				if(a[j]==i)
				{
					d[i]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		std::cout<<d[i]<<" ";
	}
	return 0;
}
