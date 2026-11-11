#include <bits/stdc++.h>
using namespace std;
int c,n,m,m1[500010],d,q,k[510],a[500][500010],t[500][500010],l,r,stl[500010],stl1[500010],x,y,mintime=100000,i,j;
void bfs(int z,int ti)
{
	if(z==y)
	{
		if(ti<mintime)
		{
			mintime=ti;
		}
		return;
	}
	if(stl1[a[z][0]]==0 and stl1[a[z][1]]==0)
	{
		return;
	}
	stl[z]=0;
	for(int i1=0;i1<n;++i1)
	{
		if(a[i1][0]==z and stl[a[i1][1]]!=0)
		{
			bfs(a[i1][1],ti+t[i1][1]+t[i1][0]);
		}
		if(a[i1][1]==z and stl[a[i1][0]]!=0)
		{
			bfs(a[i1][0],ti+t[i1][1]+t[i1][0]);
		}
	}
}
int main()
{
	freopen("subway.in","/r",stdin);
	freopen("subway.out","/w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=0;i<m;++i)
	{
		cin>>m1[i];
		stl[i]=1;
	}
	for(i=0;i<n;++i)
	{
		cin>>k[i];
		for(j=0;j<k[i];++j)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(i=0;i<q;++i)
	{
		cin>>x>>y;
		if(7<=c and c<=11)
		{
			bfs(x,m1[x]);
		}
	}
	mintime+=m1[y];
	cout<<mintime;
	return 0;
} 
