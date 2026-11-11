#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[300005];
//int d[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				if(b[k]==a[j])
				{
					for(int l=k;l<=j;l++)
					{
						b[l]=0;
					}
					break;
				}
			}
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
