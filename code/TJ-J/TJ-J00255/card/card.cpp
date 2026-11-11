#include <bits/stdc++.h>
using namespace std;
int a[5000000];
int sum[5000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		bool f[550000];
		int fl[550000];
		for(int o=0;o<550000;o++)
		{
			f[o]=0;
			fl[o]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
				fl[a[j]]=j;
			}
			else if(f[a[j]]!=0)
			{
				fl[a[j]]=j;
				for(int k=fl[a[j]];k<=j;k++)
				{
					f[k]=0;
				}
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j])sum[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}
