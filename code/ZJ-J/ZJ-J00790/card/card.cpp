#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],nxt[500005],v[500005],s[500005],f[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(!v[a[i]])
		{
			v[a[i]]=i;
		}
		else
		{
			nxt[i]=v[a[i]];
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;)
		{
			if(nxt[i])
			{
				s[i]++;
				s[nxt[i]]--;
				i=nxt[i];
			}
			else
			{
				i++;
			}
		}
		for(int i=j;i<=n;i++)
		{
			s[i]+=s[i-1];
		}
		for(int i=j;i<=n;i++)
		{
			if(s[i]==0)
			{
				f[a[i]]++;
			}
			s[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
}
