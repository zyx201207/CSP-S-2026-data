#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005],last[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j==last[a[j]])
			{
				cnt[a[j]]++;
			}
			else
				j+=(last[a[j]]-j-1);
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
