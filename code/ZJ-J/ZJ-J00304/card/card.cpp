#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],ans[300005],tt=0;
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
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]])
			{
				for(int k=t[a[j]];k<=j;k++)
				{
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int l=1;l<=m;l++)
		{
			if(t[l])
			{
				ans[l]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}