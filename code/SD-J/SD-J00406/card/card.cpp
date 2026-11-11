#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5],b[m+5];
	bool c[m+5];
	stack <long long> rong;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]])
			{
				while(rong.top()!=a[j])
				{
					rong.pop();
				}
			}
			else
			{
				rong.push(a[j]);
				c[a[j]]=1;
			}
		}
		while(!rong.empty())
		{
			b[rong.top()]++;
			rong.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
