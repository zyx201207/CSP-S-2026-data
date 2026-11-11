#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
int Test_id,Test_n;
long long n,d;
long long p[N];
bool vis[N];
long long _s[N],_p[N];
long long s_[N],p_[N];


long long num[5050],dis[5050];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&Test_id,&Test_n);
	if(Test_id<=10)
	{
	while(Test_n--)
	{
		long long Ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&p[i]);
//			printf("%lld\n",1000000000000000000 +p[i]);
		}
		for(int start=1;start<n;start++)
		{
			for(int i=0;i<=n+3;i++)
			{
				num[i]=0;
				dis[i]=1e18;
			}
			num[start]=1;
			dis[start]=0;
			for(int x=start;x<=n;x++)
			{
				long long tt=dis[x];
				if(num[x]==2)Ans++;
//				if(num[x]>2)break;
				for(long long y=x+1;y<=n&&p[y]-p[x]<=d;y++)
				{
//					printf("%d %d %lld %lld\n",x,y,dis[x],dis[y]);
					if(dis[y]>dis[x]+1)
					{
						dis[y]=dis[x]+1;
						num[y]=num[x];
					}
					else if(dis[y]==dis[x]+1)
					{
						num[y]+=num[x];
					}
//					printf("%lld %lld   %d %d %lld %lld\n\n",p[y],p[x],x,y,dis[x],dis[y]);
				}
			}
//			for(int i=start+1;i<=n;i++)
//			{
//				printf("%d->%d  ",start,i);
//				printf("%lld %lld   ",dis[i],num[i]);
//			}
//			printf("\n");
		}
		printf("%lld\n",Ans);
	}
		return 0;
	}
	while(Test_n--)
	{
		memset(vis,0,sizeof(vis));
		long long Ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&p[i]);
		}
		vis[1]=vis[n]=1;
		for(int i=2;i<=n-1;i++)
		{
			if(p[i+1]-p[i-1]>d)
			{
//				printf("check vis%d: %d %d %lld\n",i,p[i+1],p[i-1],p[i+1]-p[i-1]);
				vis[i]=1;
			}
//			printf("%d  %d\n",i,vis[n-1]);
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d",vis[i]);
//		}
//		printf("vis\n");
		_s[1]=1;
		_p[1]=1;
		int ll,rr;
		ll=1;
		rr=1;
		for(int i=2;i<=n;i++)
		{
			while(ll<=i&&p[i]-p[ll]>d)ll++;
			while(rr<=i&&p[i+1]-p[rr]>d)rr++;
			if(i==n)
			{
				rr=n+1;
			}
			_p[i]=rr-ll;
			if(p[i]-p[i-1]>d||_s[i-1]==0)
			{
				_s[i]=_p[i];
			}
			else
			{
				_s[i]=(_s[i-1])*vis[i]+1;
			}
		}
		s_[n]=1;
		p_[n]=1;
		ll=n;
		rr=n;
		for(int i=n-1;i>=1;i--)
		{
			while(ll>=i&&p[ll]-p[i-1]>d)ll--;
			while(rr>=i&&p[rr]-p[i]>d)rr--;
			if(i==1)
			{
				ll=0;
			}
			p_[i]=rr-ll;
			if(p[i+1]-p[i]>d||s_[i+1]==0)
			{
				s_[i]=p_[i];
			}
			else
			{
				s_[i]=(s_[i+1])*vis[i]+1;
//				printf("? %d",vis[i]);
			}
//			printf("s_:%d %lld\n",i,s_[i]);
		}
		for(int i=2;i<=n-2;i++)
		{
			long long l1=p[i];
			long long l2=p[i+1];
			long long ix,iy;
			long long x,y;
			int l,r,ans;
			l=1,r=i-1,ans=i;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(l2-p[mid]<=d)
				{
					r=mid-1;
					ans=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			ix=ans;
			l=i+2,r=n,ans=i+1;
			while(l<=r)
			{
				long long mid=(l+r)/2;
				if(p[mid]-l1<=d)
				{
					l=mid+1;
					ans=mid;
				}
				else
				{
					r=mid-1;
				}
			}
			iy=ans;
			x=p[ix];
			y=p[iy];
			if(y-l1<=d&&l2-x<=d&&y-x>d&&ix!=i&&iy!=i+1)
			{
				long long _i=i-ix;
				long long i_=iy-i-1;
				Ans=Ans+(_i-1)*(i_-1)+(_i-1)*(s_[iy])+(_s[ix])*(i_-1)+(_s[ix])*(s_[iy]);
//				printf("	%d %d %d %d\n",ix,i,i+1,iy);
//				printf("	%lld %lld   %lld\n",_s[ix],s_[iy],Ans);
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
