#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,vis[500005],ans[500005];
stack<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			int k=a[i];
			if(!vis[k])vis[k]=1;
			else
			{
				while(q.top()!=k)
				{
					vis[q.top()]=0;
					q.pop();
				}
				vis[q.top()]=0;
				q.pop();
			}
			q.push(k);
			vis[k]=1;
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			vis[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
