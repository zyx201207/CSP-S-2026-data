#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],l,b[N],t[N];
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
		l=0;
		for(int j=i;j<=n;j++)
		{
			l=l+1;
			b[l]=a[j];
			for(int k=l-1;k>=1;k--)
			{
				if(b[k]==b[l])
				{
					for(int x=k;x<=l;x++)
					{
						b[x]=0;
					}
					l=k;
					b[l]=a[j];
					break;
				}
			}
		}
		for(int j=1;j<=l;j++)
		{
			t[b[j]]=t[b[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}



