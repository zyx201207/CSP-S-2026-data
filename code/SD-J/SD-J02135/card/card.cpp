#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e4+5;

int n,m;
int a[N][N];
int num[N];
int f[N][N];
int fa=1;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1][i];
		f[1][i]=1;
		for(int j=1;j<=i;j++)
		{
			a[j][i]=a[1][i];
			f[j][i]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[1][i]<a[1][i-1])
		{
			fa=0;
		}
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j--)
			{
				if(a[i][j]==a[i][i])
				{
					for(int k=j;k<=n;k++)
					{
						num[a[i][k]]++;
					}
					break;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<num[i]<<" ";
		}
	}
	else if(!fa)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i][j]==a[i][k])
					{
						for(int l=j;l<k;l++)
						{
							a[i][l]=0;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				num[a[i][j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<num[i]<<" ";
		}
	}
	else if(fa)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[i][j]==a[i][j-1])
				{
					f[i][j-1]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j])
				{
					num[a[i][j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<num[i]<<" ";
		}
	}
	return 0;
}
