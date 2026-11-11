#include<bits/stdc++.h>
using namespace std;
int n,m,a[15005],cnt[15005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			int flag=1;
			if(a[i]==a[j])
			{
				flag=i;
				cnt[i]++;
			}
			if(flag!=1)
			{
				for(int k=j;k<=flag;j++)
				{
					a[k]='';
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			cout<<cnt[i];
		}
	}
	return 0;
}