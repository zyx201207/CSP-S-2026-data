#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=INT_MAX,maxn,maxans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum&=a[i];
		maxn=max(a[i],maxn);
	}
	if(n==m)
	{
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxans=max(maxans,a[i]&a[j]);
			}
		}
		cout<<maxans;
		return 0;
	}
	cout<<0;
	return 0;
}
