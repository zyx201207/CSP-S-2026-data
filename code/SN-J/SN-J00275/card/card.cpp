#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],but[500100],flag[500100],ddd[500100],tot=0;
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
		tot=0;
		memset(but,0,sizeof(but));
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				for(int k=1;k<=tot;k++)
				{
					if(but[k]==a[j])
					{
						for(int h=k;h<=tot;h++)
						{
							flag[but[h]]--;
						}
						tot=k-1;
						break;
					}
				}
			}
			but[++tot]=a[j];
			flag[a[j]]++;
		}
		for(int i=1;i<=tot;i++)
		{
			ddd[but[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ddd[i]<<' ';
	}
	return 0;
}

