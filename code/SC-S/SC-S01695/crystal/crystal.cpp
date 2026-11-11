#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],d[500010],sum,num,sum2=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<a[i]&&sum+a[i]-a[j]<=m)
			{
				sum+=a[i]-a[j];
				sum2++;
			}
			if(a[i]==a[j]&&i!=j) sum2++;
		}
		num=max(num,sum2);
		sum=0;
		sum2=1;
	}
	cout<<num;
	return 0;
}