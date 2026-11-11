// jrlzy 3 migrate
#include <bits/stdc++.h>
#define LL long long
#define SH short
#define DB long double
const int N=5005;
using namespace std;
int C,n,t[N][N],q[N],ct; LL d,a[N];
int g (int i) { int j=i; while (j<n&&a[j+1]-a[i]<=d) ++j; return j; }
void mian ()
{
	cin>>n>>d; for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) q[i]=g(i);
	for (int i=1;i<=n;++i)
	{
		int x=q[i],y=x-1;
		while (y<n)
		{
			x=q[x],y=q[y]; for (int j=y+1;j<=x;++j) ++t[i][j];
		}
	}
	for (int i=1;i<=n;++i) for (int j=i;j>=1;--j) t[j][i]+=t[j+1][i];
	for (int i=1;i<=n;++i) for (int j=i+1;j<=n;++j)
	{
		if (a[j]-a[j-1]>d) break; if (t[i][j]==1) ++ct;
	}
	cout<<ct<<'\n';
}
int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T; cin>>C>>T; while (T--)
		mian();
	exit(0);
}
