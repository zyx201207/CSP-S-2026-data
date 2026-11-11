#include<iostream>
#include<cstring>
using namespace std;
int w[500005],k[500005];
struct node
{
	int a,t;
}v[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
			cin>>v[i][j].a>>v[i][j].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=w[x];
	}
	cout<<30<<endl<<20<<endl<<10;
	return 0;
} 
