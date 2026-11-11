#include<bits/stdc++.h>
using namespace std;
const int M=3001;
int a[5005];
int c[M];
int d[M];
int n,m;
int mx=-1,mxi=1;
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int t=1;t<=n;t++)
	{
		int h[101]={};
		h[t]=a[t];
		for(int i=t+1;i<=n;i++)
		{
			h[i]=a[i];
			for(int j=t;j<i;j++)
			{
				if(h[j]==h[i])
				{
					for(int r=j;r<i;r++)
					{
						h[r]=-1;
					}
				}
			}
		}
		for(int i=t;i<=n;i++)
			if(h[i]!=-1)
				c[h[i]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;

	if(n<=100)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]=max(c[a[i]],i);
	}
	
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
}