#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],ct;
int s[5000005];
int find(int x)
{
	for(int i=1;i<=ct;i++)
	{
		if(s[i]==x)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ct=0;
		for(int j=i;j<=n;j++)
		{
			if(find(a[j]))
			{
					ct=find(a[j])-1;
			}
			s[++ct]=a[j];
		}
		for(int j=1;j<=ct;j++)
		{
			cnt[s[j]]++;
		}
	}
		for(int i=1;i<=m;i++)
		{
			printf("%d",cnt[i]);
		}
	return 0;
}
