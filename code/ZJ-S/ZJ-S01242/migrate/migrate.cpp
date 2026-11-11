#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,INF=1e18;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=(sum<<1)+(sum<<3)+c-48;c=getchar();}
	return sum*f;
}
int x[N],dp[N],cnt[N],c,t,n,d,ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for(int test=1;test<=t;test++)
	{
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++) {x[i]=read();}
		for(int l=1;l<=n;l++)
		{
			for(int i=l;i<=n;i++)
			{
				dp[i]=INF,cnt[i]=0;
				if(i==l) dp[i]=0;
			}
			for(int i=l+1;i<=n;i++)
			{
				for(int j=i;j>=l;j--)
				{
					if(x[i]-x[j]>d) break;
					dp[i]=min(dp[i],dp[j]+1);
				}
				for(int j=i;j>=l;j--)
				{
					if(x[i]-x[j]>d) break;
					if(dp[j]+1==dp[i]) cnt[i]++;
				}
			}
			for(int i=l;i<=n;i++) {if(cnt[i]==2) ans++;}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 15
1 5 10 15 25 30
*/