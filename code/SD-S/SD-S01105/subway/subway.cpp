#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
const int N=505,M=3e6+5,INF=2e9;
struct Node
{
	int z,qz;
}v[N];
struct node
{
	int b1,b2,va;
}a[M],x[N*100];
int d[N][N],w[N],fa[N],l=0,xd=0;
int c,n,m,cc,q,kk;
//n是线路，m是站台 
int cmp(node a1,node a2)
{
	a1.va<a2.va;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
/*void kruscal()
{
	for(int i=1;i<=l;i++)
	{
		//cerr << a[i].b1 << " " <<a[i].b2 << endl;
		if(find(a[i].b1)==find(a[i].b2)) continue;
		//cout << 1;
		int f1=find(a[i].b1),f2=find(a[i].b2);
		xd++;
		//cerr << xd;
		if(a[i].b1>a[i].b2) swap(a[i].b1,a[i].b2);
		x[xd]=a[i];
		d[x[xd].b1][x[xd].b2]=x[xd].va;
		//cerr << d[x[xd].b1][x[xd].b2] << ";" << x[xd].b1 << ";" << x[xd].b2 << " ";
		fa[f2]=fa[f1];
	}
}*/
void floyd()
{
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=k+1;j<=m;j++)
			{
				//if(k==2&&i==1&&j==3) cout << 1111 << endl;
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> cc >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			d[i][j]=INF;
			if(i==j) d[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin >> kk;
		for(int j=1;j<=kk;j++)
		{
			cin >> v[j].z >> v[j].qz;
			for(int k=1;k<j;k++)
			{
				l++;
				a[l].b1=v[j].z;
				a[l].b2=v[k].z;
				a[l].va=v[k].qz+v[j].qz;
				//cout << v[k].qz << ";" << v[j].qz << endl;
				if(a[l].b1>a[l].b2) swap(a[l].b1,a[l].b2);
				d[a[l].b1][a[l].b2]=min(d[a[l].b1][a[l].b2],a[l].va);
			}
		}
		memset(v,0,sizeof(v));
	}
	for(int i=1;i<=m;i++)
	{
		fa[i]=i;
	}
	//sort(a+1,a+l+1,cmp);
	//kruscal();
	floyd();
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin >> u >> v;
		if(u>v) swap(u,v); 
		cout << d[u][v]+w[u]+w[v] << endl;
	}
	return 0;
}
