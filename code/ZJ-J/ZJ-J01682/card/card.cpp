#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int n,m;
int ans[maxn];
int mp[maxn];
bool vis[maxn];
bool Vis[maxn];
int lst;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			vis[j]=0;
			mp[a[j]]=0;
			Vis[a[j]]=0;
		}
		for (int j=i;j<=n;j++)
		{
			if(mp[a[j]]!=0)
			{
				for (int k=mp[a[j]];k<j;k++)
				{
					vis[k]=1;
					mp[a[k]]=0;
				}
			}
			mp[a[j]]=j;
		}
		for (int j=i;j<=n;j++)
			if((!Vis[a[j]])&&(!vis[j]))
			{
				Vis[a[j]]=1;
				ans[a[j]]++;
			}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m)
			cout<<" ";
	}
}
