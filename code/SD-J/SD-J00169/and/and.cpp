#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m,mx,x,y,he;
bool cmp(long long x,long long y)
{
	return x>y;
}
bool qf(long long n)
{
	long long p=n;
	while(p!=0)
	{
		if(p%2==1 && p!=1)
		{
			return false;
		}
		p/=2;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	he=a[1];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		he&=a[i];
	}
	if(m==1)
	{
		cout<<mx;
	}
	else if(n==m)
	{
		x=a[1];
		for(long long i=1;i<=n;i++)
		{
			x&=a[i];
		}
		cout<<x;
	}
	else if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				x=a[i]&a[j];
				y=max(x,y); 
			}
		}
		cout<<y;
	}
	else if(m==n-1)
	{
		he+=1073741824;
		for(long long i=1;i<=n;i++)
		{
			x=max(he^a[i],x);
		}
		cout<<x;
	}
	else if(qf(n))
	{
		x=n-1;
		for(int i=n-1;i>=n-m;i--)
		{
			x&=i;
		}
		cout<<x;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
} 
