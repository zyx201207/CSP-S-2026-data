#include<bits/stdc++.h>
#define PII pair<int,int> 
#define pid first
#define pt second
#define int long long
using namespace std;
const int N=510,M=5e5+10,INF=1e17;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=(sum<<1)+(sum<<3)+c-48;c=getchar();}
	return sum*f;
}
int g[N][N],w[M],po[M];
PII t[M][30];
int c,n,m,d,q,ans=INF;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) {w[i]=read();}
	for(int i=1,ki;i<=n;i++)
	{
		ki=read();
		for(int j=1,ai,ti;j<=ki;j++)
		{
			ai=read(),ti=read();
			po[ai]++,t[ai][po[ai]].pid=i,t[ai][po[ai]].pt=ti;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) g[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j1=1;j1<=po[i];j1++)
		{
			for(int j2=1;j2<=po[i];j2++)
			{
				int id1=t[i][j1].pid,t1=t[i][j1].pt,id2=t[i][j2].pid,t2=t[i][j2].pt;
				if(id1==id2) continue;
				g[id1][id2]=min(g[id1][id2],t1+t2);
				g[id2][id1]=min(g[id2][id1],t1+t2);
			}
		}
	}
	floyd();
	for(int i=1,xi,yi;i<=q;i++)
	{
		ans=INF,xi=read(),yi=read();
		for(int j1=1;j1<=po[xi];j1++)
		{
			for(int j2=1;j2<=po[yi];j2++)
			{
				int id1=t[xi][j1].pid,t1=t[xi][j1].pt,id2=t[yi][j2].pid,t2=t[yi][j2].pt;
				ans=min(ans,w[xi]+t1+g[id1][id2]+t2+w[yi]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/