#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000005],i,maxn,x,y,b[1000005],k,c[1000005],u=1,j,d[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]!=0)
		{
			b[++k]=a[i]%2;
			a[i]/=10;
			i++;
		}
	}
	for(i=1;i<=k;i++)
	for(j=k;j>=1;j--)
	c[i]=b[j];
	for(i=1;i<=k;i++)
	for(j=i+1;j<=k;j++)
	d[i]=c[i]&b[j];
	x=d[i]*u*2;
	cout<<x;
	return 0;
}