#include<bits/stdc++.h>
using namespace std;
long long int v,w,n,m,z,a[200005],maxn=-1,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(v=1;v<=n;v++)
	{
		cin>>a[v];
		if(a[v]>maxn)
		maxn=a[v];
	}
	sum=a[1];
	for(v=1;v<n;v++)
	{
		sum=sum&a[v+1];
	}
	if(m==n)
	{
		cout<<sum<<endl;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn<<endl;
		return 0;
	}
	for(v=1;v<=n;v++)
	{
		if(a[v]&a[v+1]>maxn)
		maxn=a[v]&a[v+1];
	}
	return 0;
} 
