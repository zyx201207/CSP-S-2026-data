#include<bits/stdc++.h>

using namespace std;

const int P=998244353;
const int N=1e6+10,M=2e6+10;

long long n,ans=0,m;
long long a[N],maxn,summ;
long long s[N];
bool flag,flag1;
void dfs(long long x,long long cnt,long long sum)
{
	if(cnt>m)
	{
		return;
	}
	if(x==n+1)
	{
		if(cnt==m)
		{
			ans=max(ans,sum);
		}
		return;
	}	
	if(sum==-1)
	{
		dfs(x+1,cnt+1,a[x]);
		dfs(x+1,cnt,sum);
	}
	else
	{
		dfs(x+1,cnt,sum);
		dfs(x+1,cnt+1,sum&a[x]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]!=i-1)
		{
			flag=1;
		}
		int x=a[i]+1;
		if(x&(x-1)==0)
		{
			flag1=1; 
		}
	}
	summ=a[1];
	for(int i=2;i<=n;i++)
	{
		summ&=a[i];
	}
	if(n<=20)
	{
		dfs(1,0,-1);
		cout<<ans;
		return 0;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			cout<<maxn;
		}
		else if(m==n)
		{
			cout<<summ;
		}
		else
		{
			int maxna=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						int op=(a[i]&a[j]);
						maxna=max(maxna,op);
					}
				}
			}
			cout<<maxna;
		}
		return 0;
	}
	else if(flag==0)
	{
		cout<<n-m<<endl;
		return 0;
	}
	else if(flag1==0)
	{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	else
	{
		sort(a+1,a+n+1,greater<int>());
		summ=a[1];	
		for(int i=2;i<=n;i++)
		{
			summ&=a[i];
		}
		cout<<summ<<endl;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
