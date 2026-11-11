#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[50001],dot[30001];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i-1]!=a[i]) dot[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dot[i]<<" ";
	}
	return 0;
} 