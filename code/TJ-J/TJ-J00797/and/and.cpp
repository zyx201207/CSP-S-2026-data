#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],c[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	if(m==n)
	{
		int b=a[1];
		for(int i=2;i<=n;i++)
		{
			b&=a[i];
		}
		cout<<b;
		return 0;
	}
	else if(m==1)
	{
		cout<<c[n];
	}
	else if(m==2)
	{
		int x=c[n]&c[n-1];
		cout<<x;
	}
	else if(m==n-1)
	{
		int num=c[2];
		for(int i=2;i<=n;i++)
		{
			num&=c[i];
		}
		cout<<num;
	}
	else if(c[n]<=4)
	{
		int s1,s2,s3,s4;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) s1++;
			else if(a[i]==2) s2++;
			else if(a[i]==3) s3++;
			else if(a[i]==4) s4++;
		}
		if(m<=s4) cout<<4;
		else if(m<=s3) cout<<3;
		else if(m<=s2+s3) cout<<2;
		else if(m<=s1) cout<<1;
		else cout<<0;
	}
	else
	{
		int cnt=c[n-m+1];
		for(int i=n-m+1;i<=n;i++)
		{
			cnt&=c[i];
		}
		cout<<cnt;
	}
	return 0;
 } 
