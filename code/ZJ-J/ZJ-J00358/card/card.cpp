#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010],n,m;
vector<int> v;
int f(int x)
{
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]==x) return v.size()-i;
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int b=f(j);
			if(b==0) v.push_back(a[j]);
			else
			{
				for(int z=1;z<=b;z++)
				{
					v.pop_back() ;
				}
			}
		}
		while(!v.empty())
		{
			c[v.size()]++;
			v.pop_back();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
