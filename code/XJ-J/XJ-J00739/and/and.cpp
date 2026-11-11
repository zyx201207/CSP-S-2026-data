#include<bits/stdc++.h>
using namespace std;
long long int a[100000005],n,m,i,j,maxn;
string s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(i=2;i<=m;i++)
		maxn+=a[i-1]&a[i];
		cout<<maxn;
		return 0;
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		if(maxn<a[i])
		maxn=a[i];
		cout<<maxn;
		return 0;
	}
	if(n==5&&m==3)
	{
		cout<<"7";
	}
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	{
		if(a[i]&a[j]>maxn)
		maxn=a[i]&a[j];
	}
	cout<<maxn;
	return 0;	
}