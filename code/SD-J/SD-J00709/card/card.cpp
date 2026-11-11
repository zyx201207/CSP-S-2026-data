#include <bits/stdc++.h>
using namespace std;

struct Node{
	bool has=0;
	int last=1e9;
}st[300010];

int n,m,a[500010],mn[300010],ans[300010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=i;j<=n;j++)
		{
			st[now+1].has=0;
			st[now+1].last=1e9;
			if(st[a[j]].has==0)
			{
				mn[++now]=a[j];
				st[a[j]].has=1;
				st[a[j]].last=j;
			}
			else
			{
				if(st[a[j]].last>now)
				{
					mn[++now]=a[j];
					st[a[j]].has=1;
					st[a[j]].last=j;
				}
				else
				{
					now=st[a[j]].last-1;
					mn[++now]=a[j];
				}
			}
		}
		for(int j=1;j<=now;j++)
		{
			ans[mn[j]]++;
		}
		memset(mn,0,sizeof mn);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
