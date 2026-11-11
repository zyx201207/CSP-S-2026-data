#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],pre[N],b[N],L[N],R[N],dp[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{	
				cin>>a[i];	
			}
			int z=1;
			for(int i=1;i<=n;i++)
			{
				while(z!=n&&a[z+1]-a[i]<=d)
				z++;
				pre[i]=z;
			}
			int ans=0;
			for(int i=1;i<=1;i++)
			{
				b[i]=0;
				L[0]=R[0]=i;
				int z=i;
				while(pre[z]!=z)
				{
					b[z+1]=b[z]+1;
					for(int j=z+2;j<=pre[z];j++)
					{
						b[j]=b[j-1];
					}
					L[b[z]+1]=z+1;
					R[b[z]+1]=pre[z];
					z=pre[z];
				}
				L[b[z]+1]=z+1;
				dp[i]=1;
				dp[i+1]=-1;
				for(int j=i;j<z;j++)
				{
					dp[j]+=dp[j-1];
					int l1=L[b[j]+1];
					int r1=R[b[j]+1];
					r1=min(r1,pre[j]);
					if(r1>=l1)
					{
						if(dp[j]>2)
						{
							dp[l1]+=3;
							dp[r1+1]-=3;
						}
						else
						{
							dp[l1]+=dp[j];
							dp[r1+1]-=dp[j];	
						} 
					}
				}
				dp[z]+=dp[z-1];
				for(int j=i;j<=z;j++)
				{
					ans+=(n-j+1)*(dp[j]==2);	
				} 
				for(int j=1;j<=n+1;j++)
				{
					dp[j]=0;
				}
			}
			cout<<ans<<'\n';
		} 
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{	
			cin>>a[i];	
		}
		int z=1;
		for(int i=1;i<=n;i++)
		{
			while(z!=n&&a[z+1]-a[i]<=d)
			z++;
			pre[i]=z;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
			L[0]=R[0]=i;
			int z=i;
			while(pre[z]!=z)
			{
				b[z+1]=b[z]+1;
				for(int j=z+2;j<=pre[z];j++)
				{
					b[j]=b[j-1];
				}
				L[b[z]+1]=z+1;
				R[b[z]+1]=pre[z];
				z=pre[z];
			}
			L[b[z]+1]=z+1;
			dp[i]=1;
			dp[i+1]=-1;
			for(int j=i;j<z;j++)
			{
				dp[j]+=dp[j-1];
				int l1=L[b[j]+1];
				int r1=R[b[j]+1];
				r1=min(r1,pre[j]);
				if(r1>=l1)
				{
					if(dp[j]>2)
					{
						dp[l1]+=3;
						dp[r1+1]-=3;
					}
					else
					{
						dp[l1]+=dp[j];
						dp[r1+1]-=dp[j];	
					} 
				}
			}
			dp[z]+=dp[z-1];
			for(int j=i;j<=z;j++)
			{
				ans+=(dp[j]==2);	
			} 
			for(int j=1;j<=n+1;j++)
			{
				dp[j]=0;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0; 
}

