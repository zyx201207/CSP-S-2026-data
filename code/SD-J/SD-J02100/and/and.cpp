#include<bits/stdc++.h>
using namespace std;
long long n,maxn,m;
bool b=0;
long long ans;
long long a[200005]; 
void dfs(long long now,int yx,int i,bool b)
{

	if(yx==m)
	{
		
		ans=max(now,ans);
		return;
	}
	if(i>n)
	{
		return;
	}
	dfs(now,yx,i+1,b);
	if(b==0)
	{
		now=a[i];
		dfs(now,yx+1,i+1,1);
	}
	else
	{
		now&=a[i];
		
	}
	dfs(now,yx+1,i+1,1);
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		dfs(0,0,1,0);
		cout << ans;
		return 0;
	}
	else if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			maxn=max(a[i],maxn);
		}
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		if(m==1)
		{
			cout << maxn;
			return 0;
		}
		if(m==n)
		{
			cout << ans;
			return 0;
		}
		long long cnt=0;
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					cnt=max(cnt,a[i]&a[j]);
				}
			}
			cout <<cnt;
			return 0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]%2==0)
			{
				b=1;
			} 
		}
		
		sort(a+1,a+n+1);
		cout << a[n-m+1];
		return 0;
	}
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
