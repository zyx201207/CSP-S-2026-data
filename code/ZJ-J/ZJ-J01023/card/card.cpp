#include <bits/stdc++.h>
using namespace std;
int n,m,a[300010],cnt[300010],ans[300010];
bool flag[300010];
stack <int> q;
queue <int> q1;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q1.push(a[i]);
	}
	
	for(int f=1;f<=n;f++)
	{
		for(int i=1;i<=n;i++) flag[i]=0;
		while(!q1.empty())
		{
			int x=q1.front();
			q1.pop();
			if(flag[x]==1)
			{
				while(q.top()!=x&&!q.empty())
				{
					int y=q.top();
					flag[y]=0;
					q.pop();
				}
			}
			flag[x]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(flag[i]==1) cnt[i]++;
		}
		for(int i=n-f;i<=n;i++)
		{
			q1.push(a[i]);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}