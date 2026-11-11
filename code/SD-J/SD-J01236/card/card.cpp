#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
queue<int> q;
queue<int> tmp;
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		vis[a[i]]=1;
		for(int k=i+1;k<=n;k++)
		{
			bool ff=1;
			for(int j=1;j<=m;j++)
			{
				if(!vis[j] && a[k]==j)
					break;
				if(vis[j] && a[k]==j)
				{
					bool falg=1;
					while(!q.empty())
					{
						int p=q.front();
						q.pop();
						if(a[k]==p)
							falg=0;
						if(falg)
						{
							tmp.push(a[k]);
							continue;
						}
						vis[p]=0;
					}
					while(!tmp.empty())
					{
						int p=tmp.front();
						tmp.pop();
						q.push(p);
					}
					vis[a[k]]=1;
					q.push(a[k]);
					ff=0;
				}
			}
			if(ff)
			{
				vis[a[k]]=1;
				q.push(a[k]);
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j])
			{
				cnt[j]++;
				vis[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
