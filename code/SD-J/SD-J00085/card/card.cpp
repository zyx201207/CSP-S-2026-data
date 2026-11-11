#include<bits/stdc++.h>
using namespace std;
vector<int> a(200005);
int b[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a.push_back(i);
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[k]<=a[j])
				{
					a.pop_back();
				}
			}
			a.push_back(j);
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i]==j)
			{
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
