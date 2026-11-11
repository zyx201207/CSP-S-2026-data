#include<bits/stdc++.h>
using namespace std;

long long a[2000000],c[2000000],k,ans,n; 

struct awe
{
	long long cha,a,r;
}b[2000000];

bool cmp(long long a,long long b)
{
	return a>b;
}

bool cmp1(awe a,awe b)
{
	if(a.a!=b.a)
	{
		return a.a>b.a;
	}
	return a.cha<b.cha;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		b[i].a=a[i];
		b[i].r=a[i+1];
		b[i].cha=a[i]-a[i+1];
	}
	sort(b+1,b+n,cmp1);	
	c[1]=b[1].a;
	c[2]=b[1].r;
	for(int i=2;i<=n;i++)
	{
		c[i+1]=b[i].r;
	}
	ans=c[1];
	for(int i=2;i<=k;i++)
	{
		ans=ans&c[i]; 
	}	
	cout<<ans;
	
	return 0;
}
