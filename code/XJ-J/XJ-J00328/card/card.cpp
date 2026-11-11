#include<bits/stdc++.h>
using namespace std;
long long n, m, a[100005];
long long op[100005] = {0}, sum[100005] = {0};
stack<int> q;
stack<int> s;
stack<int> r;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++)
	{
		cin>>a[i];
	}
	for(int i = n; i >= 1; i --)
	{
		
			if(op[a[i]] == 0)
			{
				op[a[i]] = 1;
				q.push(a[i]);
				while(!q.empty())
				{
					s.push(q.top());
					q.pop();
				}
				while(!s.empty())
				{
					q.push(s.top());
					s.pop();
				}
			}
			else
			{
				while(q.top() != a[i])
				{
					op[q.top()] = 0;
					q.pop();
					
				}
				
			}
			while(!q.empty())
			{
				sum[q.top()]++;
				s.push(q.top());
				q.pop();
			}
			while(!s.empty())
			{
				q.push(s.top());
				s.pop();
			}
	}
	for(int i = 1; i <= m; i ++)
	{
		cout<<sum[i]<<' ';
	}
	return 0;
 } 
