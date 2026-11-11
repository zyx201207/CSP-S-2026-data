#include<bits/stdc++.h>
//long long
#define ll long long
using namespace std;
ll read()
{
	ll k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int n;
long long m;
const int N=500010;
ll a[N];
bool check(int mid)
{
	ll top=a[n],sum=0;
	for(int i=n-1;i>=n-mid+1;i--) sum+=a[i];
	sum=a[n]*(mid-1)-sum;
	if(sum<=m) return 1;
	for(int i=n-mid;i>=1;i--) 
	{
		sum-=(mid-1)*(a[i+mid]-a[i+mid-1]);
		sum+=a[i+mid-1]-a[i];
		if(sum<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=ceil((l+r)*1.0/2);
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}


