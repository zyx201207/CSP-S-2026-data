#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100005],s,maxs=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s=a[i]*a[j];
		}
		if(s>maxs)
		{
			maxs=s;
		}
	}
	cout<<maxs;
	return 0;
}