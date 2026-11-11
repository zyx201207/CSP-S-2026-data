#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N];
long long r[N];
long long dp[N],dpp[N],op[N],opp[N],dpk[N];
long long yp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		r[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			r[i]=r[i+1];
			while(a[r[i]]-a[i]>d) r[i]--;
		}
		for(int i=1;i<=n;i++) dpk[i]=0;
		long long ans=0;
		dp[n]=1;
		for(int i=n-1;i>=1;i--) 
		{
			if(r[i]==i)
			{
				dp[i]=1;
				continue ;
			}
			dp[i]=dp[r[i]]+r[i]-i;
			if(r[i]-1!=i)
			{
				int x=r[r[i]-1];
				if(x>r[i]) dp[i]-=x-r[i],dpk[i]-=x-r[i];
			//	if(dp[i]<dp[r[r[i]]]) cout<<dp[r[i]]<<" "<<dp[r[r[i]]]<<"\n";
				if(r[r[i]]!=r[i]&&x==r[r[i]]) dpk[i]-=dp[r[r[i]]]-1+dpk[r[i]],dp[i]-=dp[r[r[i]]]-1+dpk[r[i]];
				//if(dp[r[i]]<dp[r[r[i]]]&&r[r[i]]!=r[i])
			//	cout<<dp[r[i]]<<" "<<dp[r[r[i]]]<<"\n";
			}
		}
	//	for(int i=1;i<=n;i++) cout<<dp[i]<<" "<<dpp[i]<<"a\n";
	//	for(int i=1;i<=n;i++) dp[i]+=dp[i-1],dpp[i]+=dpp[i-1];
		for(int i=1;i<=n;i++) op[i]=opp[i]=yp[i]=0;
		for(int i=1;i<=n;i++)
		{
			op[i]++;
			
			if(r[i]!=i) 
			{
				op[r[i]]+=op[i]+opp[i];
				int x=r[r[i]];
				if(x!=r[i]&&r[i]-1!=i)
				{
					if(r[r[i]-1]==x) opp[r[i]]-=op[i]+opp[i];
					if(r[r[i]-1]==x-1) yp[r[i]]-=op[i]+opp[i];
				//	cout<<r[i]<<" "<<x<<"ss\n";
				}	
			}
		}
	/*	for(int i=1;i<=n;i++)
		{
			if(r[i]!=i)
			{
				int x=r[r[i]];
				if(x!=r[i]&&r[i]-1!=i)
				{
					if(r[r[i]-1]==x) opp[x]-=op[i]+opp[i];
				//	cout<<op[r[i]]<<" "<<x<<"ss\n";
				}	
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(r[i]!=i) opp[r[i]]+=opp[i];
		}
	//	for(int i=1;i<=n;i++) op[i]+=opp[i];*/
		for(int i=1;i<=n;i++)
		{
			if(r[i]==i||r[i]==i+1) continue ;
		//	if(opp[i]!=0) continue ;
		op[i]+=opp[i]+yp[i];
			if(r[i]==i+2)
			{
				int x=r[r[i]-1];
				if(x>r[i]) 
				{
					int z=r[r[i]];
					if(z==r[i]) ans+=op[i]*(x-r[i]);
					else
					{
						ans+=op[i]*(min(x,z-1)-r[i]);
						
						if(x==z) ans+=op[i]*(dp[r[i]]-(z-r[i]));
					}
				}
			}
			else
			{
				int x=r[r[i]-1];
				
				if(x>r[i]) 
				{	
					int z=r[r[i]];
					if(z==r[i]) ans+=op[i]*(x-r[i]);
					else
					{
						ans+=op[i]*(min(x,z-1)-r[i]);//cout<<ans<<"a";
						if(x==z) ans+=op[i]*(dp[r[i]]-(z-r[i]));
					}
				//	ans+=op[i]*(x-r[i]);
				}
				int y=r[r[i]-2];
				if(y>r[i]) 
				{
					int z=r[r[i]];
					if(z==r[i]) ans-=op[i]*(y-r[i]);
					else
					{
						ans-=op[i]*(min(y,z-1)-r[i]);
						if(y==z) ans-=op[i]*(dp[r[i]]-(z-r[i]));
					}	
				}
			}
		op[i]-=opp[i]+yp[i];
		//	cout<<i<<":"<<ans<<"\n";
		}
		
	/*for(int i=1;i<=n;i++) 
			if(dp[i]<0)
			{
				cout<<i<<":"<<dp[i]<<"\n";
			}*/
	//	for(int i=1;i<=n;i++) cout<<r[i]<<" ";
	//	cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/ 
