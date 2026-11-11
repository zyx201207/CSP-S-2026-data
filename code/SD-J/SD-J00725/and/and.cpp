#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
int n,m;
int a[N];
int ans=0;
int ds[N];
int st[N];
struct handsome{
	int a,b,c;
}p[N];
int solve2(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%2;
		x/=2;
	}
	return ans;
}
int solve(int x)
{
	int ans=0;
	while(x)
	{
		ans*=10;
		ans+=(x%2);
		x/=2;
	}
	return ans;
}
bool ddmp(handsome x,handsome y)
{
	return x.c>y.c;
}
bool cmp(handsome x,handsome y)
{
	return x.b>y.b;
}

void dfs(int u,int cnt)
{
	if(cnt==m)
	{
		int num=0;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(st[i]==1)
			{
				sum++;
				if(sum==1)
				{
					num=(num|a[i]);
				}
				if(sum>1)
				{
					num=(num&a[i]);
				}
			}
		}
		if(num==1)
		{
			for(int i=1;i<=n;i++)
		{
			if(st[i])
			{
				cout<<a[i]<<' ';
			}
		}
		cout<<"\n";
		}
	 	ans=max(num,ans);
		return;
	}
	if(u>n)
	{
		return;
	}
	dfs(u+1,cnt);
	st[u]=1;
	dfs(u+1,cnt+1);
	
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	int mm=a[1];
	for(int i=2;i<=n;i++)
	{
		mm=(mm&a[i]);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		cout<<mm;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		p[i].a=a[i];
		p[i].b=solve(a[i]);
		p[i].c=solve2(a[i]);
	}
	sort(p+1,p+1+n,ddmp);
	sort(p+1,p+1+n,cmp);
	int ans=p[1].a;
	for(int i=2;i<=m;i++)
	{
		ans=(ans&p[i].a);
	}
	cout<<ans;
return 0;
}
//5 3 
//31 3 1 15 7
//4 2
//3 15 12 12
