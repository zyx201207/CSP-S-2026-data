#include <bits/stdc++.h>
using namespace std;
long long n,m,q;
struct node
{
	long long x,num1;
}a[200005];
bool cmp(node a,node b)
{
	if(a.num1!=b.num1) return a.num1>b.num1;
	return a.x>b.x;
}
long long nm(long long x,long long y)
{
	string a="",b="";
	while(x)
	{
		if(x%2==0) a='0'+a;
		else a='1'+a;
		x/=2;
	}
	while(y)
	{
		if(y%2==0) b='0'+b;
		else b='1'+b;
		y/=2;
	}
	string t="";
	for(int i=min(a.size(),b.size())-1;i>=0;i--)
	{
		if(a[i]==b[i]&&a[i]=='1') t+='1';
		else t+='0';
	}
	long long cnt=0,jl=1,len=min(a.size(),b.size());
	for(long long i=0;i<len;i++)
	{
		cnt+=1LL*(t[i]-'0')*jl;
		jl*=2;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i].x;
		long long t=a[i].x,sum=0;
		while(t)
		{
			if(t%2==1) sum++;
			t/=2;
		}
		a[i].num1=sum;
	}
	sort(a+1,a+n+1,cmp);
	q=a[1].x;
	for(int i=2;i<=m;i++)
	{
		q=nm(q,a[i].x);
	}
	cout<<q;
    return 0;
}
