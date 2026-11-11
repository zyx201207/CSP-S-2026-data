#include<bits/stdc++.h>
using namespace std;
int n,m,hea,tai;
stack<int> q;
int ans[300005],vis[300005],pai[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>pai[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(vis[pai[j]]==1)
			{
				while(q.top()!=pai[j])
				{
					vis[q.top()]=0;
					q.pop();
				}
				q.pop();
				
			}
			q.push(pai[j]);
			vis[q.top()]=1;
			
			
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
