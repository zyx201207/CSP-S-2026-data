#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005],n,m,ans[500005],d[500005];
struct node
{
	int x,y;
}b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]].x++;
		b[a[i]].y=i;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int r=1;r <= m;r++)
		{
			if(c[r])ans[r]++;
		}
		for(int l = i;l <= n;l++)
		{
			c[l]=0;
		}
		c[a[i]]=a[i];
		for(int j = i;j <= n;j++)
		{
			d[j]=b[j];
			if(d[a[i]].x>1&&b[a[i]].y==j)
			{
				d[a[i]]-=2;
				for(int k = 1;k <= j;k++)c[k]=0;
				c[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i];
	}
	return 0;
}
