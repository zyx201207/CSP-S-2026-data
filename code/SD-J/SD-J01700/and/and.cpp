#include <iostream>

using namespace std;
using ll=long long;

const int N=2e5+5;

int n,m;
int a[N];
int ans;
int maxn;

void dfs(int i,int k,int sum)
{	
	if(k==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(i==n+1) return;
	if(k>m+1) return;	
	
	if(k==0)
	{
		dfs(i+1,k,sum);
		dfs(i+1,k+1,a[i]);
	}
	else
	{
		dfs(i+1,k,sum);
		dfs(i+1,k+1,(sum&a[i]));
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	maxn=a[1];
	for(int i=2;i<=n;i++) 
	{
		cin>>a[i];
		ans=(ans&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(n==m) 
	{
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int k=a[2];
		for(int i=3;i<=n;i++) k=(k&a[i]);
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans=a[1];
				if(i!=j) ans=(ans&a[j]);
			}
			k=max(ans,k);
		}
		cout<<k;
		return 0;
	}
	ans=0;
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
