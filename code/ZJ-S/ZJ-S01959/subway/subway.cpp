#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000101,M=1011;
int c,n,m,d,Q,w[N],k[N],a[M][M],t[M][M],q[N],f[N],x,y,item[N],F[N]; //!
struct no
{
	int s,m;
}eq[M][M];
void Bfs (int x)
{
	int l=1,r=1;
	q[r]=x;f[x]=0;
	for (int i=1;i<=item[x];i++)
	{
		int fx=eq[x][i].s;
		r++,q[r]=fx;f[fx]=eq[x][i].m;
	}
	while (l<=r)
	{
		int fx=q[l];
//		cout <<fx<<" "<<f[fx]<<"\n";
		for (int i=1;i<=item[fx];i++)
		{
			int sx=eq[fx][i].s;
			if (f[sx]>f[fx]+eq[fx][i].m) r++,q[r]=sx,f[sx]=f[fx]+eq[fx][i].m;
//			cout <<sx<<" "<<f[sx]<<"\n";
		}
//		cout <<"\n"; 
		l++;
	}
}
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>Q;
	for (int i=1;i<=m;i++) cin >>w[i];
	for (int i=1;i<=n;i++)
	{
		cin >>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin >>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k[i];j++)
			for (int qw=1;qw<=k[i];qw++)
			{
				eq[a[i][j]][item[a[i][j]]+1].m+=t[i][qw];
				if (qw==j) continue ;
				item[a[i][j]]++;
				eq[a[i][j]][item[a[i][j]]].s=a[i][qw];
			}
	}
//	for (int i=1;i<=m;i++)
//	{
//		for (int j=1;j<=item[i];j++) cout <<eq[i][j].s<<" ";
//		cout <<"\n";
//	}
//	cout <<"\n";
//	for (int i=1;i<=m;i++)
//	{
//		for (int j=1;j<=item[i];j++) cout <<eq[i][j].m<<" ";
//		cout <<"\n";
//	}
//	cout <<"\n";
	while (Q--)
	{
		cin >>x>>y;
		for (int i=1;i<=m;i++) f[i]=INT_MAX,F[i]=0;
		Bfs (x);
//		cout <<"\n";
//		for (int i=1;i<=m;i++) cout <<f[i]<<" ";
//		cout <<"\n";
		cout <<f[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3



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
