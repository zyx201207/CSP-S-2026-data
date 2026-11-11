//T2被创飞了，好难啊
//这是线性DP吗？不会写 
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,d;
int x[2000005];
int minv=INT_MAX;
int sum,ans;
void dfs(int s,int t,int k)
{
	if(s==t)
	{
		if(k<minv)
		{
			minv=k;
			sum=1;
		}
		else if(k==minv)
		{
			sum++;
		}
		return;
	}
//	int p=upper_bound(x+s,x+t+1,x[s]+d)-x;
//	if(x[p]>x[s])
//	{
//		dfs(s,p-1,k+1);
//	}
	for(int i=s+1;i<=t;i++)
	{
		if(x[i]-x[s]<=d)
		{
			dfs(i,t,k+1); 
		}
		else
		{
			break;
		}
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n<=9)
		{
			for(int i=1;i<=n-2;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					minv=INT_MAX;
					sum=0;
					dfs(i,j,0);
					if(sum==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else
		{
			cout<<0<<'\n';
		}
	}
	return 0;
} 
