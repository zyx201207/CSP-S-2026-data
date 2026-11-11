#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[500010],st[500010],d[500010],t;
bool b[500010];
void check(int u)
{
	for(int i=u;i<=n;i++)
	{
		if(!st[a[i]])
		{
			d[++t]=a[i];
			st[a[i]]=t;
		}
		else
		{
			t=st[a[i]];
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(!b[d[i]])
		{
			cnt[d[i]]++;
			b[d[i]]=1;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(st,0,sizeof st);
		memset(d,0,sizeof d);
		memset(b,0,sizeof b);
		t=0;
		check(i);
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
 	return 0;
}