#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,a[100000005],b[10005][10005],c,maxn,sum,r,k,l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	j=1;
	for(i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]>maxn)
	maxn=a[i];
}
	if(m==1)
	{
	cout<<maxn;
	return 0;
    }
if(m==2)
{
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	if((a[i]&a[j])>sum)
	sum=a[i]&a[j];
	cout<<sum;
}
return 0;
}
