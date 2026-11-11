#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000005],b[1000005],c[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j; 
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
	b[i]=a[i+1]-a[i];
	for(j=2;j<=n;j++)
	{
	for(i=1;i<j;i++)
	c[j]+=b[i]*i;	
	if(c[j]>m)
	{
	cout<<j-1;	
	return 0;	
	}	
	}
	cout<<n; 
	return 0;
}
