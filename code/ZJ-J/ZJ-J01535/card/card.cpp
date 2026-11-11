#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans[N],st[N];
bool flag=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]<a[i-1])flag=0;
	}
	if (flag)
	{
		for (int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
		}
	}
	else if (m<=2)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==a[n])ans[a[i]]++;
			else ans[1]++,ans[2]++;
		}
	}
	else 
	{
		for (int k=1;k<=n;k++)
		{
			int i=k;
			memset(st,0,sizeof st);
			for (int i=k;i<=n;i++)
			{
				if (st[a[i]])
				{
					for (int j=st[a[i]];j<=i;j++)st[a[j]]=0;
				}
			 	st[a[i]]=i;
			}
			for (int i=1;i<=m;i++)
			{
				if (st[i])ans[i]++;
			}
		}
	}
	for (int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
