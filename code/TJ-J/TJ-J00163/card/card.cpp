#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[300005],j[300005],x[500005],c;
stack<int>s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	c=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	while(c<=n)
	{
		for(int i=c;i<=n;i++)
		{
			if(a[x[i]]==0) 
			{
				s.push(x[i]);
				a[x[i]]++;
			}
			else 
			{
				while(s.top()!=x[i]&&!s.empty())
				{
					a[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			j[s.top()]++;
			a[s.top()]--;
			s.pop();
		}
		memset(a,0,sizeof(a));
		c++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<j[i]<<' ';
	}
	return 0;
}

