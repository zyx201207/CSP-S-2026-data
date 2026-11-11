#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	long long a[20005],sum,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++)
	{
		sum=(a[i]&a[i+1]);
		for(int j=i+2;j<=m;j++)
		{
			sum=(sum&a[j]);
		}
		if(sum>t)
		{
			t=sum;
		}
	}
	cout<<t;
	return 0;
 } 
