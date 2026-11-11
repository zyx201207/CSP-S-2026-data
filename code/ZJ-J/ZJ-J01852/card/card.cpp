#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[500005];
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==1)
			{
				while(!q.empty())
				{
					q.pop();
				}
				for(int i=1;i<=n;i++)
				{
					b[i]=0;
				}
			}
			q.push(a[j]);
			b[a[j]]=1;
		}
		while(!q.empty())
		{
			if(b[q.front()]==1)
			{
				ans[q.front()]++;
				b[q.front()]=0;
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}