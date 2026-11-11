#include <cstdio>
const int N=2001000;
long long a[N];
int cnt[N],dp[N],pre_cnt[N];
int nxt[N];
inline int max(int a,int b)
{
	return (a > b) ? a : b;
}
long long read()
{
	long long num=0,f=1;
	char c=getchar();
	while(!(c>='0' && c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		if(c<=10)
		{
			long long answer=0;
			for(int i=1;i<=n;i++)
			{
				dp[i]=0;
				cnt[i]=1;
				pre_cnt[i]=1;
				for(int j=i+1,l=i,r=i;j<=n;j++)
				{
					while(l<j && a[j]-a[l]>d) l++;
					r=max(l,r);
					while(r<j && dp[l]==dp[r]) r++;
					if(l==j)
					{
						break;
					}
					dp[j]=dp[l]+1;
					if(dp[l]==dp[r])
					{
						cnt[j]=pre_cnt[r]-pre_cnt[l-1];
					}
					else
					{
						cnt[j]=pre_cnt[r-1]-pre_cnt[l-1];
					}
					if(cnt[j]>3)
					{
						cnt[j]=3;
					}
					pre_cnt[j]=pre_cnt[j-1]+cnt[j];
					if(cnt[j]==2)
					{
						answer++;
					}
				}
				for(int j=i;j<=n;j++)
				{
					dp[j]=cnt[j]=pre_cnt[j]=0;
				}
			}
			printf("%lld\n",answer);
		}
		else if(c==11 || c==12)
		{
			if(n==1)
			{
				printf("0\n");
			}
			else
			{
				long long tmp=d/(a[2]-a[1]);
				if(tmp==0)
				{
					printf("0\n");
				}
				else if(tmp==1)
				{
					printf("0\n");
				}
				else
				{
					long long ans=n-(2*tmp)+1;
					if(ans>0) printf("%lld\n",ans);
					else printf("0\n");
				}
			}
		}
		else if(c==13 || c==14)
		{
			nxt[n]=n;
			for(int i=n-1,j=n;i>=1;i--)
			{
				while(j>i && a[j]-a[i]>d) j--;
				nxt[i]=j;
			}
			long long answer=0;
			for(int i=1;i<=n;i++)
			{
				int j=nxt[i];
				answer+=nxt[j-1]-nxt[j-2];
			}
			printf("%lld\n",answer);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
