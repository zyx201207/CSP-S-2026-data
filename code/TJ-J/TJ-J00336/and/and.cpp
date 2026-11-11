#include<iostream>
#include<algorithm>
using namespace std;
long long a[200005];
int n,m;
long long di(int ci,long long num,int fi)
{
	if(fi+1==n)
	{
		return num&a[fi];
	}
	long long ma=0;
	for(int i=fi;i<n-m+ci;i++)
	{
		ma=max(ma,di(ci+1,num&a[i],i+1ll));
	}
	return ma;
}
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long ma=a[0];
	for(int i=1;i<m;i++)
	{
		ma=ma&a[i];
	}
	cout<<ma;
	return 0;
}
