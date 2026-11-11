#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int maxn=2e6+5;
int c,t;
long long n;
long long x[maxn],lst,cnt,ans;
unsigned long long d,nowd;
bool A;

void dfs(long long st,long long ed,long long c)
{
	if(c>lst)return;
	if(st==ed)
	{
		cnt++;
	}
	if(cnt>2)return;
	for(long long i=st+1;i<=ed&&x[i]-x[st]<=d;i++)
	{
		dfs(i,ed,c+1);
	}
}

void scan(long long st,long long ed)
{
	cnt=1;
	lst=1;
	long long step=st,c=1;
	while(step!=ed)
	{
		if(x[step+1]-x[step]>nowd)
		{
			lst++;
			nowd=d-x[step+1]+x[step];
			step++;
		}
		else
		{
			nowd=nowd-x[step+1]+x[step];
			step++;
		}
	}
	dfs(st,ed,1);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		A=1;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			if(A&&i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])A=0;
		}
		if(A)
		{
			cnt=d/(x[2]-x[1]);
			cnt*=2;
			ans=n-cnt+1;
			printf("%lld",ans);
		}
		else
		{
			for(long long i=1;i<=n-3;i++)
			{
				for(long long j=i+3;j<=n;j++)
				{
					scan(i,j);
					if(cnt==2)ans++;
				}
			}
			printf("%lld",ans);
		}
	}
	return 0;
}
