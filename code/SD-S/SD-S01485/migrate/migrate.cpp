#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,T,n,d,A[N],to[N],INF=5e18;
int dis[N],tim[N];
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			A[i]=read();
		if(c==11||c==12)
		{
			int x=A[2]-A[1];
			int what=d/x,ahanum0=0;
			if(what<=1) printf("0\n");
			else printf("%lld\n",max(n+1-(2*what),ahanum0));
			continue;
		}
//		memset(dis,0,sizeof(dis)),
//		memset(tim,0,sizeof(tim));
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			dis[i]=0,tim[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				dis[j]=INF,tim[j]=1;
				for(int z=j-1;z>=i;z--)
				{
					if(A[j]-A[z]>d)
						break;
					if(dis[j]>dis[z]+1)
						dis[j]=dis[z]+1,
						tim[j]=tim[z];
					else if(dis[j]==dis[z]+1)
						tim[j]+=tim[z];
					if(tim[j]>2)
						break;
				}
				if(tim[j]==2)
					++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
