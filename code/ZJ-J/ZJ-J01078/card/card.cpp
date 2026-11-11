#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],f[300005],lst[300005],MAX=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		memset(f,0,sizeof(f));
		memset(lst,0,sizeof(lst));
		for(int i=k;i<=n;i++)
		{
			if(lst[a[i]]>0&&f[a[i]])
			{
				for(int j=lst[a[i]];j<i;j++)
				{
					if(f[a[j]]>0)
					{
						f[a[j]]--;
					}
				}
			}
			f[a[i]]++;
			lst[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			if(f[i]>0)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
