#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,d,q,i,j,r;
	cin>>c>>n>>m>>d>>q;
	//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	int w[m+1],k[n+1],x,y,s;
	long long int a[n+1][500002],t[n+1][500002];
	for(i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>k[i];
		for(j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(r=0;r<q;r++)
	{
		cin>>x>>y;
		s=w[x]+w[y];
	}
}
