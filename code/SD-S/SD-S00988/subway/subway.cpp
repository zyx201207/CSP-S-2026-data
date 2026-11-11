#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1001],k,a[1001],t[1001],fd[1001][1001];
int main()
{	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(fd,0x3f,sizeof(fd));
	while(n--)
	{	cin>>k;
		for(int j=1;j<=k;j++)
		{	cin>>a[j]>>t[j];
			for(int x=1;x<j;x++)
			{	fd[a[x]][a[j]]=min(fd[a[x]][a[j]],t[j]+t[x]);
				fd[a[j]][a[x]]=min(fd[a[j]][a[x]],t[j]+t[x]);
			}
		}
	}
	for(int x=1;x<=m;x++)
		for(int y=1;y<=m;y++)
			for(int z=1;z<=m;z++)
				fd[y][z]=min(fd[y][z],fd[y][x]+fd[x][z]);
	while(q--)
	{	int x,y;
		cin>>x>>y;
		cout<<fd[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
