#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N],b[N],c[10];
bool flag[N];
void dfs(int t)
{
	if(t==m)
	{
		int sum=b[1];
		for(int i=2;i<=t;i++)
		{
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			b[++t]=a[i];
			dfs(t);
			flag[i]=0;
			t--;
		}
	}
}
bool power(int x)
{
	while(x)
	{
		if((x&1)==0)
		{
			return 0;
		}
		x>>=1;
	}
	return 1;
}
int main()
 {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2&&n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sum=a[i]&a[j];
				ans=max(ans,sum);
			}
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(0);
		cout<<ans;
	}
	else
	{
		bool f1=1,f2=1,f3=1;
		if(power(n-1)==0)
		{
			f2=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=i-1)
			{
				f2=0;
			}
			if(a[i]>4)
			{
				f3=0;
			}
			if(power(a[i])==0)
			{
				f1=0;
			}
		}
		if(f1==1)
		{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
		else if(f2==1)
		{
			ans=a[n];
			for(int i=n-1,j=2;j<=m;i--,j++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
		}
		else if(f3==1)
		{
			for(int i=1;i<=n;i++)
			{
				c[a[i]]++;
			}
			if(c[3]+c[2]>=m)
			{
				cout<<2;
			}
			else if(c[3]+c[1]>=m)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/