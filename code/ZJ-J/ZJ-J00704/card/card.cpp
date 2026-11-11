#include<bits/stdc++.h>
using namespace std;

int a[500005],ans[300005],ls[300005];
bool x[300005];

int main()
{
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> q;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[n-i+1];
	}
	for(int i=1;i<=n;i++)
	{
		if(x[a[i]])
		{
			while(q.top()!=a[i]||q.empty())
			{
				x[q.top()]=0;
				q.pop();
			}
		}
		else
		{
			q.push(a[i]);
			x[a[i]]=1;
		}
		int cnt=0;
		while(!q.empty())
		{
			ls[++cnt]=q.top();
			ans[q.top()]++;
			q.pop();
		}
		cout<<'\n';
		for(int i=cnt;i>=1;i--)
		{
			q.push(ls[i]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
 	return 0;
}

