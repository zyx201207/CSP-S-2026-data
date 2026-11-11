#include<bits/stdc++.h>
using namespace std;
int e[300001];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		int c[n+1];
		bool b[m+1];
		int d[m+1];
		int y=1;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]=1;
				c[y]=a[j];
				d[a[j]]=y;
				y++;
			}
			else
			{
				for(int x=d[a[j]];x<y;x++)
				{
					c[x]=0;
					b[c[x]]=0;
				}
				y=d[a[j]];
				c[y]=a[j];
				b[c[y]]=1;
				y++;
			}
		}
		for(int j=1;j<y;j++)
		{
			e[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<e[i]<<" ";
	}
	return 0;
}
