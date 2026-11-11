#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],m,i,j,maxn=0,b[200000005],k,t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m--;
	t=n;
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	b[i]=a[i]&a[j];
	while(--m)
	{
		for(i=1;i<=n;i++)
		for(j=1;j<=t;j++)
		b[++k]=a[i]&b[j];
		t=k;
		k=0;
	}
	for(i=1;i<=t;i++)
	maxn=max(maxn,b[i]);	
	cout<<maxn;
	return 0;
}
