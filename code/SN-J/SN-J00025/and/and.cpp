#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  n,m,max=0;
	cin>>n>>m;
	int  ans[n],a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(long long i=0;i<n-m;i++)
{
	ans[i]=a[i];
	for(long long d=1;d<m;d++)
	{
		ans[i]=ans[i]&a[i+d];
	}
	if(ans[i]>max)
	max=ans[i];
}
cout<<max;
	return 0;
}
