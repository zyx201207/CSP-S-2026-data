#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
map<int,int>mp;
int zm[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				zm[++cnt]=a[j];
				b[a[j]]++;
			}
			else
			{
				for(int k=1;k<=cnt;k++)
				{
					if(zm[k]==a[j])
					{
						cnt=k-1;
						break;
					}
				}
				zm[++cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			mp[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<" ";
	}
	return 0;
}
