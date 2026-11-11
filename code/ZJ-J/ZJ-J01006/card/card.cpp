#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500020],b[300020],c[300020],d[500020];
queue <int> q;
queue <int> qu;
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		d[i] = a[i];
	}
	sort(d+1,d+1+n);
	for(int i = 1;i <= n;i++)
	{
	    qu.push(d[i]);
		if(d[i] == d[i-1])
		{
			qu.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		c[i] = qu.front();
		qu.pop();
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			for(int k = i;k < j;k++)
			{
				if(a[j] == a[k])
				{
					for(int h = k;h <= j-1;h++)
					{
						if(q.size() > 0)
						{
							q.pop();
						}
					}
					continue;
				}
			}
			q.push(a[j]);
		}
		for(int j = 1;j <= q.size();j++)
		{
			b[q.front()]++;
			q.pop();
		}
	}
	b[c[m]]++;
	for(int i=1;i <= m;i++)
	{
		cout << b[c[i]] << " ";
	}
	return 0;
}
