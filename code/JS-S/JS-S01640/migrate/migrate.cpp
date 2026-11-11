#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,ans;
long long x[2000500];
long long dp[5050],mi[5050];
bool ofA,ofm;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		ofA=true,ofm=false,ans=0;
		if(n<=5000)
			ofm=true;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",x+i);
			if(i>=3)
				ofA&=(x[i]-x[i-1])==(x[i-1]-x[i-2]);
		}
		if(ofm)
		{
			for(long long l=1;l<=n;l++)
			{
				long long last=l,now=1;
				memset(mi,0x3f,sizeof mi);
				mi[l]=0;
				for(long long i=l+1;i<=n;i++)
				{
					if(x[i]-x[i-1]>d)
						break;
					if(x[i]-x[last]>d)
						now++,last=i-1;
					mi[i]=now;
				}
				long long sum,ba=l;
				dp[l]=1;
				for(long long i=l+1;i<=n;i++)
				{
					if(mi[i]-1==mi[i-1])
					{
						while(mi[ba]!=mi[i]-1||x[i]-x[ba]>d)
							ba++;
						sum=0;
						for(long long j=ba;j<=i-1;j++)
							sum+=dp[j];
					}
					while(x[i]-x[ba]>d)
						sum-=dp[ba],ba++;
					dp[i]=sum,ans+=dp[i]==2;
				}
			}
			printf("%lld\n",ans);
		}
		else if(ofA)
		{
			long long k=x[2]-x[1];
			d/=k;
			if(d==1)
			{
				puts("0");
				continue;
			}
			long long len=2ll*d-1ll;
			n--;
			if(len<=1||n<len)
			{
				puts("0");
				continue;
			}
			printf("%lld\n",n-len+1);
		}
		else
		{
			long long v=-1;
			for(long long i=1;i<=n;i++)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
				{
					v=i;
					break;
				}
			if(v==-1)
			{
				puts("0");
				continue;
			}
			long long un=0,v1=n+1,unn=0,v11=n+1;
			for(long long i=n;i>=v;i--)
			{
				if(x[i]-x[v-2]<=d)
					break;
				v1=i;
			}
			for(long long i=1;i<=v;i++)
			{
				if(x[v+2]-x[i]<=d)
					break;
				un=i;
			}
			for(long long i=n;i>=v;i--)
			{
				if(x[i]-x[v-1]<=d)
					break;
				v11=i;
			}
			for(long long i=1;i<=v;i++)
			{
				if(x[v+1]-x[i]<=d)
					break;
				unn=i;
			}
			printf("%lld\n",(un-unn+1)*(n-v11+1)+(unn-1)*(v11-v1));
		}
	}
	return 0;
}
