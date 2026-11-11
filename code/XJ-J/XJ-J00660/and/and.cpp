#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200010],flag[200010],x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		int u,v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int k=a[i]&a[j];
			if((k>x)&&(i!=j))
			{
				x=k;
				u=i;
				v=j;
			}
		}
	}
	if(m<=2)
	{
		cout<<x;
		return 0;
	}
	flag[u]=1;
	flag[v]=1;
	for(int o=0;o<m-2;o++)
	{
		int j;
		long long int maxx=-1;
		for(int i=0;i<n;i++)
		{
			int k=x & a[i];
			if((k>=maxx)&&(flag[i]==0))
			{
				maxx=k;
				j=i;
			}
		}
		flag[j]=1;
		x=maxx;
	}
	cout<<x;
	return 0;
}
