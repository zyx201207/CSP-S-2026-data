#include<bits/stdc++.h>
using namespace std;
int x[500005],a[500005],n,m;
int main()
{
		freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			x[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<x[i]<<" ";
	}
}