#include<bits/stdc++.h>
using namespace std;
bool f(stack<int> s, int x)
{
	while(!s.empty())
	{
		if(s.top()==x)
			return true;
		s.pop();
	}
	return false;
}
stack<int> s;
int cnt[300050]={0};
int a[500050], n, m;
void era()
{
	bool b[300050]={false};
	while(!s.empty())
	{
		b[s.top()]=1;
		s.pop();
	}
	for(int i=1; i<=m; i++)
	{
		if(b[i])
			cnt[i]++;
	}
	return;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			if(f(s, a[j]))
			{
				int t=s.top();
				while(t!=a[j])
				{
					s.pop();
					t=s.top();
				}
			}
			else
			{
				s.push(a[j]);
			}
		}
		era();
	}
	for(int i=1; i<=m; i++)
	{
		cout<<cnt[i];
		if(i!=m)
		{
			cout<<" ";
		}
	}
	return 0;
}
