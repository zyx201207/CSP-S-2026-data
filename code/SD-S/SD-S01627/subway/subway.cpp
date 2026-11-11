#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[1010][1010],v[1000010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		int ka,at,ta;
		cin>>ka;
		for(int j=1;j<=ka;j++)
		{
			cin>>at>>ta;
			a[m+i][at]=ta;
			a[at][m+i]=ta;
		}
	}
	for(int k=1;k<=n+m;k++)for(int i=1;i<=n+m;i++)for(int j=1;j<=n+m;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(int i=1;i<=q;i++)
	{
		int s,e;
		cin>>s>>e;
		cout<<v[s]+a[s][e]+v[e]<<"\n";
	}
	return 0;
}
