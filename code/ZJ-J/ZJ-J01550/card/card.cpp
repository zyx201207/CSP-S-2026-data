#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
vector<int> d;
bool p[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			o=1;
		}
	}
	if(!o)
	{
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]!=a[i-1])
			{
				b[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				d.push_back(a[j]);
				bool u=0;
				int s=d.size();
				for(int k=0;k<s;k++)
				{
					if(u)
					{
						d.pop_back();
						continue;
					}
					if(a[j]==d[k])
					{
						u=1;
					}
				}
			}
			for(int j=d.size()-1;j>=0;j--)
			{
				b[d[j]]++;
				d.pop_back();
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}