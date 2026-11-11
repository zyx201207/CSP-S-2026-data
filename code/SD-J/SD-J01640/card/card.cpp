#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans[500010],sum[500050];
int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+ans[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}

