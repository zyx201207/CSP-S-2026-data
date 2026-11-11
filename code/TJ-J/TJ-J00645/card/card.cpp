#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],c[500005],p[500005][500005];
signed main()
{
	int cnt=0,cnt2=0;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt2=0;
		for(int j=i;j<=n;j++)
		{
			for(int k1=1;k1<=m;k1++)
			{
				
				if(c[k1]>1)
				{
					cnt2=0;
				}
			c[a[j]]++;
			cnt2++;
		
			}
		}
		for(int j=1;j<=m;i++)
		{
			p[j][n]=c[j];
			c[j]=0;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<p[j][n]<<" ";
		}
	}
	return 0;
}


