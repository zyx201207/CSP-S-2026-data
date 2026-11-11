#include<bits/stdc++.h>
#define int long long
using namespace std;
int same(int a[],int n)
{
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			sum++;
		}
	}
	return sum;
}
const int N=5e5+10;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=m;i++)
	{
		sort(a+1,a+n+1);
		a[1]++;
		if(same(a,n)>max)
		{
			max=same(a,n);
		}
	}
	cout<<max;
	return 0;
}
