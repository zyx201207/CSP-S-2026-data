#include<bits/stdc++.h>
using namespace std;

inline long long read();

const int N=2e6+10;

int csd,T,n;
long long d;
long long x[N];
long long f[310][310],cnt[310][310];

inline long long Abs(long long a,long long b)
{
	if(a>=b)
	{
		return a-b;
	}
	else
	{
		return b-a;
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	csd=read();T=read();
	while(T--)
	{
		n=read();d=read();
		for(int i=1;i<=n;++i)
		{
			x[i]=read();
		}
		if(n<=300)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
					f[i][j]=n+1;
					cnt[i][j]=0;
					if(i!=j&&Abs(x[j],x[i])<=d)
					{
						f[i][j]=1;
						cnt[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;++i)
			{
				for(int k=i+1;k<=n;++k)
				{
					for(int j=k+1;j<=n;++j)
					{
						if(i!=j&&j!=k&&i!=k&&f[i][k]&&f[k][j])
						{
							if(f[i][j]>f[i][k]+f[k][j])
							{
								f[i][j]=f[i][k]+f[k][j];
								cnt[i][j]=cnt[i][k]*cnt[k][j];
							}
							else if(f[i][j]==f[i][k]+f[k][j])
							{
								cnt[i][j]++;
							}
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
//					cout<<i<<" "<<j<<" "<<cnt[i][j]<<"\n";
					if(i!=j&&cnt[i][j]==2)
					{
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}

inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

