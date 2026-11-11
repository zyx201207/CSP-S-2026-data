#include <bits/stdc++.h>
using namespace std;
long long a[100000];
double b[100000];
long long c[10000],n,m;
long long z=m;
double ping;
double ji[100000];
int e=1;
double zong=0;
double qu=99999999;
int realize()
{
	int cnt=0;
	ping=zong/n;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>ping) ji[i]=b[i]-ping;
		if(b[i]<ping) ji[i]=ping-b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(ji[i]<qu) qu=b[i];
	}
	for(int i=1;i<=n;i++)
		{
			int q=qu-b[i];
			if(b[i]<qu&&q<z) 
			{
				b[i]=qu;
				z-=q;
			}
		}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==qu)
		{
			cnt++;
		}
	}
	return cnt;
}
int solve(int yu)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		{
			int q=yu-a[i];
			if(a[i]<yu&&q<m) 
			{
				c[e]=q;
				e++;
			}
		}
		sort(c,c+e);
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=m&&c[i]!=0)
			{
				a[i]=yu;
				m-=c[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==yu)
			{
				cnt++;
			}
		}
		return cnt;
}
int main()
{
	double zong=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	double zhong=99999;
	int yu;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		zong+=b[i];
	}
	int cnt=0;
	//ping=zong/n;
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i]>ping) ji[i]=a[i]-ping;
//		if(a[i]<ping) ji[i]=ping-a[i];
//	}
//	cout<<ping;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<ji[i]<<" ";
//	}
	sort(b,b+n);
	int w=n/2;
	int ans;
	if(n%2==0) 
	{
	 ans=max(solve(b[w+1]),solve(b[w]));
		
	}
	else 
	{
		yu=b[w+1];
		for(int i=1;i<=n;i++)
		{
			int q=yu-a[i];
			if(a[i]<yu&&q<m) 
			{
				c[e]=q;
				e++;
			}
		}
		sort(c,c+e);
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=m&&c[i]!=0)
			{
				a[i]=yu;
				m-=c[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==yu)
			{
				cnt++;
			}
		}
	}
	int y=max(realize(),cnt);
	int p=max(y,ans);
	cout<<p;
	return 0;
}
