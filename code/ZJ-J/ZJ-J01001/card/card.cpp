#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005]={0};
int nums[300005]={0};
int num[300005]={0};
bool vis[300005]={false};
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
		for(int j=0;j<=m;j++)
		{
			num[j]=0;
			vis[j]=false;
		}
		for(int j=i;j<=n;j++)
		{
			if(num[a[j]]!=0)
			{
				for(int k=num[a[j]];k<j;k++)
				{
					vis[a[k]]=false;
					if(num[a[k]]==k)
					{
						num[a[k]]=0;
					}
				}
			}
			vis[a[j]]=true;
			num[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j]==true)
			{
				nums[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<nums[i]<<" ";
	}
	return 0;
}
