#include<bits/stdc++.h>
using namespace std;
int a[5005],vis[5005],c[3005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		stack<int> stk;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				stk.push(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while(stk.top()!=a[j])
				{
					stk.pop();
				}
				//cout<<stk.top()<<endl;
			}
		}
		while(!stk.empty())
		{
			c[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
