#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
ll tot=0,c[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		queue<ll>q,p;
		for(int j=i;j<=n;j++)
		{
			q.push(a[j]);
			c[a[j]]++;
			if(c[a[j]]>1)
			{
				ll sum=0;
				while(!q.empty())
				{
					if(q.front()!=a[j])
					{
						p.push(q.front());
					}
					if(q.front()==a[j])
					{
						q.pop();
						while(!q.empty())
						{
							if(q.front()==a[j])
							{
								p.push(q.front());
								break;
							}
							c[q.front()]--;
							q.pop();
						}
						break;
					}
					c[q.front()]--;
					q.pop();
				}
				while(!q.empty())
				{
					p.push(q.front());
					q.pop();
				}
				while(!p.empty())
				{
					q.push(p.front());
					p.pop();
				}
			}	
		}
		while(!q.empty())
		{
			p.push(q.front());
			q.pop();
		}
		while(!p.empty())
		{
			q.push(p.front());
			p.pop();
		}
		memset(c,0,sizeof(c));
		while(!q.empty())
		{
			c[q.front()]++;
			if(c[q.front()]>1)
			{
				q.pop();
			}
			else
			{
				d[q.front()]++;
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
