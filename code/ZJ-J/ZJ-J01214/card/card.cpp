#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int anss[300010];
int tab[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		memset(tab,0,sizeof(tab));
		int cur=k;
		for(int i=k;i<=n;i++,cur++)
		{
			for(int j=1;j<i;j++)
			{
				if(tab[j]==a[i])
				{
					cur=j;
					break;
				}
			}
			tab[cur]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			int f=0;
			for(int j=k;j<=cur;j++)
				if(tab[j]==i)
				{
					f=1;
					break;
				}
			anss[i]+=f;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<anss[i]<<" ";
	return 0;
}
