#include<bits/stdc++.h>
using namespace std;
int a[1000006],q[1000006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<int> s;
	stack<int> d;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool k=false;
			if(!s.empty())
			{
				while(!s.empty())
				{
					if(s.top()==a[j])
					{
						s.pop();
						k=true;
						while(!d.empty())
						{
							d.pop();
						}
						s.push(a[j]);
						break;
					}
					d.push(s.top());
					s.pop();
				}
				while(!d.empty())
				{
					s.push(d.top());
					d.pop();
				}
				if(!k)s.push(a[j]); 
			}
			else
			{
				s.push(a[i]);
			}
		}
		while(!s.empty())
		{
			q[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<q[i]<<" ";
	}
}
