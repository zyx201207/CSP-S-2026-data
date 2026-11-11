#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,q;
int u[100005],v[100005],m[10000005];
int dp[10005][10005];
int ppp(int a,int b)
{
	if(dp[a][b]!=0)
	{
		return dp[a][b];
	}
	return ppp(a+1,b)+1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		n=0;
		cin>>n>>k;
		for(int j=1;j<=n-1;j++)
		{
			cin>>u[j]>>v[j];
			dp[u[j]][v[j]]=1;
			dp[v[j]][u[j]]=1;
		}
		for(int j=1;j<=n;j++)
		{
			for(int u=1;u<=n;u++)
			{
				dp[j][u]=ppp(j,u);
			}		
		}
		for(int j=1;j<=n;j++)
		{
			for(int u=1;u<=n;u++)
			{
				m[q]=dp[j][u];
				q++;
			}
		}
		n-=1;
		for(int j=1;j<=q;j++)
		{
			for(int u=j+1;u<=q;u++)
			{
				if(m[j]<m[u])
				{
					swap(m[j],m[u]);
				}
			}
		}
		cout<<m[2+2*k];
	}
}
