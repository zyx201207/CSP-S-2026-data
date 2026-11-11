#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define gc() getchar()
#define pc(x) putchar(x)

int read()
{
	int x=0,f=1;
	char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}

void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');return ;}
	write(x/10);pc(x%10+'0');
	return ;
}

void print(int x)
{
	write(x);pc('\n');
	return ;
}
int c,T;
int n,d;
int v[310][310];
int dp[310][310];
int a[2000010];
void solve1()
{
	while(T--)
	{
		int ans=0;	
		n=read();d=read();
		for(int i=1;i<=n;i++) 
		{
			a[i]=read();
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=0;
				v[i][j]=1e9+7;
			}
		}
		for(int l=1;l<=n;l++)
		{
			for(int i=1;i+l<=n;i++)
			{
				int j=i+l;
				if(a[j]-a[i]<=d) {v[i][j]=1;dp[i][j]=1;continue;}
				for(int k=i+1;k<j;k++)
				{
					if(a[j]-a[k]>d) {continue;}
					if(v[i][k]+v[k][j]<v[i][j]) {v[i][j]=v[i][k]+v[k][j];dp[i][j]=0;}
					if(v[i][k]+v[k][j]==v[i][j])
					{
						dp[i][j]+=dp[i][k];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dp[i][j]==2) {ans++;}
			}
		}
		print(ans);
	}
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	if(c<=6)
	{
		solve1();
		return 0;
	}
	return 0;
}

//30pts 
