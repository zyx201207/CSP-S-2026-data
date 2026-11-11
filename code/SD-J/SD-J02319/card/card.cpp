#include<bits/stdc++.h> 
#define int long long
using namespace std;
int a[1000010],b[1000010],c[1000010],d[1000010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				c[b[a[j]]]++;
				c[j]--;
				for(int k=1;k<=m;k++)
				{
					if(b[k]>=b[a[j]]&&b[k]<=j)
					{
						b[k]=0;
					}
				}
			}
			b[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			c[j]+=c[j-1];
			if(c[j]==0)
			{
				d[a[j]]++; 
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
} 
