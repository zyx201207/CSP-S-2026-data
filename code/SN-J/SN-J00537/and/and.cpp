#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	long long sum=a[n]; 
	for(int i=n-1;i>=n-m;i--)
	{
		sum=sum and a[i];
	}
	cout<<sum;
	return 0;
}
