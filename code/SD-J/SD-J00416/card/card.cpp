#include <bits/stdc++.h>
using namespace std;
int n,m,x[300005],a[500005],vis[300005];
stack<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(!q.empty())
				{
					vis[q.top()]=0;
					if(q.top()==a[j])
					{
						q.pop();
						break;
					}
					q.pop();
				}
			}
			vis[a[j]]=1;
			q.push(a[j]);
		}
		while(!q.empty())
		{
			x[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << x[i] << " ";
	}
	return 0;
 } 
