#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n,m;
int a[5000010];
int cnt[300010];
int b[300010];
stack<int> q;
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
			if(b[a[j]]>0)
			{
				while(q.top()!=a[j]&&!q.empty())
				{
					b[q.top()]--;
					q.pop();
				}
				if(!q.empty())
				{
					b[q.top()]--;	
					q.pop();
				}
			}
			b[a[j]]++;
			q.push(a[j]);
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]>0)
			{
				cnt[i]++;
			}
		}
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=m;j++)
		{
			b[j]=0;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
