#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005];
stack<int> st1,st2;
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		while(!st1.empty())
		{
			num[st1.top()]++;
			st1.pop();
		}
		for(int j=i;j<=n;j++)
		{
			while(!st1.empty())
			{
				int t=st1.top();
				if(t==a[j])
				{
					f=1;
				}
				q.push(t);
				st1.pop();
			}
			if(f==1)
			{
				while(q.front()!=a[j])
				{
					q.pop();
				}
			}
			while(!q.empty())
			{
				st2.push(q.front());
				q.pop();
			}
			while(!st2.empty())
			{
				st1.push(st2.top());
				st2.pop();
			}
			st1.push(a[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
