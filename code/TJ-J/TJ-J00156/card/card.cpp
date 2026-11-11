#include <bits/stdc++.h>
using namespace std;
long long a[300005],n,m,b[300005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<long long>s;
	for(int i=1;i<=n;i++)
	{
			while(!s.empty())
			{
				s.pop();
			}
		for(int j=1;j<=i;j++)
		{
			if(b[a[j]]==1)
			{
				while(!s.empty())
				{
					s.pop();
				}
				b[a[j]]=0;
			}
			s.push(a[j]);
			b[a[j]]=1;
		}
		for(int q=1;q<=n;q++)
		{
			c[q]+=b[q];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i];
	}
	return 0;
}
