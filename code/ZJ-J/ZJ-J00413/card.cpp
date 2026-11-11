/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],mn[300005],ans[300005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		mn[a[i]]++;
		if(mn[a[i]]>1)
		{
			mn[a[i]]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]!=a[i]||mn[a[j]]==0)
				{
					mn[a[j]]=0;
				}
				else
				{
					break;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=mn[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],mn[300005],ans[300005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			ans[a[i]]+=n-i+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],mn[500005],ans[500005],nw[500005],seat[500005],top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		top++;
		mn[top]=a[i];
		nw[a[i]]++;
		if(seat[a[i]]==0)
		{
			seat[a[i]]=top;
		}
		else
		{
			nw[mn[top]]--;
			top--;
			for(;top>seat[a[i]];top--)
			{
				seat[mn[top]]=0;
				nw[mn[top]]--;
			}
			top=seat[a[i]];
		}
		for(int j=1;j<=top;j++)
		{
			ans[mn[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
