#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=509,M=1e3+9,DL=25;
const ll INF=1e17+9;

int q[M*M],ql,qr;
int vis[M],use[M];
ll mep[M][M],W[M];
ll A[M],T[M];
int c,n,m,D,Q;

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/

inline ll  read();

inline void bfs(int R,int w);

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int x,y;
	scanf ("%d %d %d %d %d",&c,&n,&m,&D,&Q);
	for (int i=1;i<=m;i++)
		W[i]=read();
	
	{
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				mep[i][j]=INF;
		for (int i=1;i<=n;i++)
		{
			x=read();
			for (int j=1;j<=x;j++)
				A[j]=read(),T[j]=read();
			for (int j=1;j<=x;j++)
				for (int k=j+1;k<=x;k++)
					mep[A[j]][A[k]]=mep[A[k]][A[j]]=T[j]+T[k];
		}
		
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
				vis[j]=use[j]=0;
			while (qr)
				q[qr--]=0;
			ql=1,qr=0;
			
			for (int j=1;j<=m;j++)
				if (mep[i][j]<INF)
					q[++qr]=j;
			bfs(i,1);
		}
		
		while (Q-->0)
		{
			x=read(),y=read();
			printf ("%lld\n",mep[x][y]+W[x]+W[y]);
		}
	}
	
	return 0;
}

inline ll   read()
{
	ll o=0,c=0,g=0;
	while (c<'0' or c>'9')
		g=(c=='-'),c=getchar();
	while (c>='0' and c<='9')
		o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return (!g)?o:-o;
}

inline void bfs(int R,int w)
{
	if (ql>qr)
		return ;
	
	int tip=qr;
	while (ql<=tip)
	{
		int x=q[ql++];
		for (int i=1;i<=m;i++)
		{
			if (i==x)
				continue;
			if (mep[R][i]>mep[R][x]+mep[x][i])
			{
				mep[R][i]=mep[R][x]+mep[x][i];
				if (!use[i])
					q[++qr]=i,use[i]=1;
			}
		}
	}
	for (int i=1;i<=m;i++)
		use[i]=0;
	bfs(R,w+1);
}

