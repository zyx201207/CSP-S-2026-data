#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int>g;
	for(int i=0;i<n;i++)
	{
		g.push_back(a[i])
		for(int j=0;j<g.size();j++)
		{
			if(a[i]==g[j])
			{
				for(int k=g.size();k>=j;k--)
				{
					g.pop(g[k]);
				}
			}
		}
		
	}
	for(int j=0;j<g.size();j++)
	{
		cout<<g[j]<<" ";
	}
}
