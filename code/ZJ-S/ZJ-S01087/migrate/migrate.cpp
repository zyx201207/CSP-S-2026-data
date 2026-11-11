#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],dp[6005][6005],sum,mn,ans;
struct node{
	int U,step;
};
queue<node>q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==12||c==11)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			cout<<max(0,n-(2*d)+1)<<endl;
		}
	}
	else if(c==14||c==13)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int i=1;i<=n;i++)
			{
				if(x[n]-x[i]<=d)break;
				int l=i,r=n,mid=0,as=0;
				while(l<=r)
				{
					mid=(l+r)/2;
					if(x[mid]-x[i]>d)
					{
						as=mid;
						r=mid-1;
					}else l=mid+1;
				}
				if(as-i==3)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					dp[i][j]=2000006;
				dp[i][i]=1;
			}
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
					sum=0,mn=2000006;
					while(!q.empty())q.pop();
					q.push({i,0});
					while(!q.empty())
					{
						int u=q.front().U,st=q.front().step;
						q.pop();
						if(sum>2||st>mn)break;
						if(u==j)
						{
							mn=min(mn,st);
							sum++;
							continue;
						}
						for(int k=u+1;k<=j;k++)
						{
							if(x[k]-x[u]>d)break;
							q.push({k,st+1});
						}
					}
					if(sum==2)ans++;
				}
			cout<<ans<<endl;
		}
	}
	return 0;
}
