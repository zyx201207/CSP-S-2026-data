#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5000005],k[505],v[500005];
struct S
{
	int to[7],si;
} s[500005];
struct L
{
	int a,t;
} l[505][500005];
struct P
{
	int x,y;
} p[100005];
void f(int r,int now,int tim)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>l[i][j].a>>l[i][j].t;
		}
	}
	for(int r=1;r<=n;r++)
	{
		cin>>p[r].x>>p[r].y;
		v[p[r].x]=1;
		f(p[r].y,p[r].x,w[p[r].x]);
		v[p[r].x]=0;
	}
	
	return 0;
}
