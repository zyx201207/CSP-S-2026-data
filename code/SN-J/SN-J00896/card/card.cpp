#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
int a[500005];
int nxt[300005];
int lst[300005];
int cnt[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f&=(a[i]>=a[i-1]);
	}
	if(f)
	{
		for(int i=2;i<=n+1;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<i-1<<' ';
			}
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(lst[a[i]]==0)
		{
			nxt[i]=-1;
		}
		else
		{
			nxt[i]=lst[a[i]];
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			while(nxt[j]!=-1)
			{
				j=nxt[j];
			}
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
