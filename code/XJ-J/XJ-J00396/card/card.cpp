#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],cnt[300005],flag,ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]!=0)
			{
				flag=1;
				continue;
			}
			else 
			{
				cnt[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=cnt[j];
			cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}