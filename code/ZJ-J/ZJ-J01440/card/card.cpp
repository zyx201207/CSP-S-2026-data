#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],vis[300003],ans[300003];
stack<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(!s.empty()&&s.top()!=a[j])s.pop();
				if(!s.empty())s.pop();
			}
			s.push(a[j]);
			vis[a[j]]=1;
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}