#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,f[500005],p[500005],len=0,need,flag;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>f[i];
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<=n-i+1;j++)
		{
			p[j]=f[j];
			flag++;
		}
		sort(p,p+flag);
		for(int j=0;j<flag;j++)
		{
			need=need+(p[flag-1]-p[j]);
		}
		if(need<=m)
		{
			len=max(len,flag);
		}
		flag=0;
		need=0;
	}
	cout<<len;
	return 0;
}
