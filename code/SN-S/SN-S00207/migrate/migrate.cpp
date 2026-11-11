#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,lf[2000010],rg[2000010],dp1[2000010][4],dp2[2000010][4],dp[5010][5010];
long long d,x[2000010];

void init()
{
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(x[i]-x[mid]<=d)
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		lf[i]=ans;
		l=i,r=n,ans=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=d)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		rg[i]=ans;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=13 && c<=14)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) 
			{
				cin>>x[i];
				lf[i]=rg[i]=0;
			}
			init();
			int tp=-1;
			for(int i=1;i<=n;i++) if(lf[i]==1 && rg[i]==n) tp=i;
			for(int i=tp;i<n;i++) x[i]=x[i+1];
			n--; 
			for(int i=1;i<=n;i++)
			{
				lf[i]=rg[i]=0;
			}
			init();
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max(0,max(rg[rg[i]],rg[i])-max(rg[i],rg[rg[i]-1]));
			}
			cout<<ans<<"\n";
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) 
			{
				cin>>x[i];
				lf[i]=rg[i]=0;
			}
			init();
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++) dp1[i][j]=dp2[i][j]=0;
				int ls=i;
				dp1[i][1]=dp1[i][2]=dp1[i][3]=1;
				while(ls!=n)
				{
					if(rg[ls]==ls) break;
					for(int j=1;j<=3;j++) dp2[i][j]=0;
					int tp=min(n,rg[ls]);
					for(int j=1;j<=min(3,tp-ls);j++)
					{
						int tt=tp-j+1;
						int pt=max(lf[tt],ls-2);
						dp2[i][j]=min(dp1[i][ls-pt+1],3);
						dp2[i][j]+=dp2[i][j-1];
					}
					if(dp1[i][1]==2) ans+=min(n,rg[ls])-max(min(n,rg[ls-1]),ls);
					if(dp1[i][1]==1 && dp1[i][2]==2) ans+=max(min(n,rg[ls-1]),ls)-max(min(n,rg[ls-2]),ls);
					ls=rg[ls];
					for(int j=1;j<=3;j++) dp1[i][j]=dp2[i][j];
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
