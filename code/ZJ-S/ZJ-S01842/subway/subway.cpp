#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,qq,ga,gb;
int w[505];
int k,__[1005];
int shi[505][1005];
bool bbb[505][1005];
int mi;
struct da
{
	int v,w;
};
vector<da>a[500005];
int t(int a,int b)
{
	return (a-1)*m+b;
}
int x,y,minl;
int d[500005];
bool v[500005];
struct da1
{
	int v,w;
};
bool operator<(da1 a,da1 b)
{
	return a.w>b.w;
}
bool bb(int x)
{
	for(int i=1;i<=n;i++)
		if(t(i,y)==x)
		{
			gb=shi[i][y];
			return 1;
		}
			
	return 0;
}
priority_queue<da1>q;
void dj(int st)
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	while(!q.empty()) q.pop();
	d[st]=0;
	q.push({st,0});
	while(!q.empty())
	{
		int x=q.top().v;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		if(bb(x))
		{
			minl=min(minl,d[x]+ga+gb);
			break;
		}
		for(int i=0;i<a[x].size();i++)
		{
			int v1=a[x][i].v;
			if(v[v1])continue;
			int w1=a[x][i].w;
			if(d[v1]>d[x]+w1)
			{
				d[v1]=d[x]+w1;
				q.push({v1,d[v1]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>__[j];
			cin>>shi[i][__[j]];
			bbb[i][__[j]]=1;
		}
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++)
			{
				if(j==l)continue;
				a[t(i,__[j])].push_back({t(i,__[l]),0});
			}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(!bbb[i][j])continue;
			for(int l=1;l<=n;l++)
			{
				if(i==l||!bbb[l][j])continue;
				a[t(i,j)].push_back({t(l,j),shi[i][j]+shi[l][j]});
			}
		}
	}
	for(int i=1;i<=qq;i++)
	{
		cin>>x>>y;
		minl=1e9;
		for(int j=1;j<=n;j++)
		{
			ga=shi[j][x];
			dj(t(j,x));
		}
		cout<<minl+w[x]+w[y]<<endl;
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/








