#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005],b[100005],flag[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	int id=1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			for(int k = 1;k <= id;k++)
			{
				if(b[k]==a[j]&&flag[k]==0)
				{
					for(int l = k;l < id;l++)flag[l]=1;
					break;
				}
			}
			b[id]=a[j],id++;
		}
		for(int j = 1;j <= id;j++)if(flag[j]==0)sum[b[j]]++;
	}
	for(int i = 1;i <= m;i++)cout<<sum[i]<<" ";
	return 0;
}
