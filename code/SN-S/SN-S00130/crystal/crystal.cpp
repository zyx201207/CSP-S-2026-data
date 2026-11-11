#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cha[500010],s[500010],sum; 
bool check(int x)
{
	long long ss;
	for(int i=1;i<=n-x+1;i++)
	{
		int r=i+x-1;
		ss=a[r]*(x-1)-s[r-1]+s[i-1];
		if(ss<=m) return true;
		
	}
	return false;
}
void f(int l,int r)
{
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid)==true) f(mid,r);
		else f(l,mid-1);
		return;
	}
	if(check(r)==true) cout<<r;
	else cout<<l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=n;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];		
	}
	f(1,n);
	return 0;
}
