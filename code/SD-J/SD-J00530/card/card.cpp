#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m,a[500005];
vector<int>q;

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==a[n-1])
	{
		for(int i=1;i<=m;i++)
		{
			if(i!=a[n])
			{
				cout<<0<<' ';
			}
		}
		cout<<n;
	}
	else
	{
		stack<int>q;
		for(int i=n;i>1;i--)
		{
			q.push(i);
			if(a[i]==a[i-1])
			{
				for(int j=1;j<a[i];j++)
				{
					cout<<0<<' ';
				}
				while(!q.empty())
				{
					cout<<q.top();
					q.pop();
				}
				return 0;
			}
		}
	}
	return 0;
}

