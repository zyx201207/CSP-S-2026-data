#include<bits/stdc++.h>
using namespace std;
struct node
{
	int line,stop;	
}a[500005];
int dis[10005][10005];
int c,n,m,d,q,len;
int find(int x,int y)
{
	for(int i=1;i<=len;i++)
	if(a[i].line==x&&a[i].stop==y)
	return i;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(dis,0x3f3f3f,sizeof(dis));
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		len++;
		a[len].line=-1;
		a[len].stop=i;
		len++;
		a[len].line=0;
		a[len].stop=i;
		dis[len][len-1]=x;
		dis[len-1][len]=x;
	}
	for(int i=1;i<=n;i++)
	{
		int k,x,y,z;
		cin>>k;
		cin>>z>>y;
		len++;
		a[len].line=i;
		a[len].stop=z;
		dis[find(i,z)][find(0,z)]=y;
		dis[find(0,z)][find(i,z)]=y;
		for(int j=2;j<=k;j++)
		{
			cin>>x>>y;
			len++;
			a[len].line=i;
			a[len].stop=x;
			dis[find(i,x)][find(0,x)]=y;
			dis[find(0,x)][find(i,x)]=y;
			dis[find(i,z)][find(i,x)]=0;
			dis[find(i,x)][find(i,z)]=0;
			z=x;
		}
	}
	for(int i=1;i<=len;i++)
	dis[i][i]=0;
	for(int k=1;k<=len;k++)
	for(int i=1;i<=len;i++)
	for(int j=1;j<=len;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[find(-1,x)][find(-1,y)]<<endl;
	}
	return 0;
} 
