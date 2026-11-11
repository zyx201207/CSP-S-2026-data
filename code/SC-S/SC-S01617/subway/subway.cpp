#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,a,a1,b,b1,e[500005][1005],f[5000005][1005];
void pri(int t)
{
	if(t==a)
	{
		for(int j=1;j<=(2*m+n);j++)
		{
			if(f[t][j]==1)
			{
				d[j]=e[t][j];
				pri(j);
			}
			else if(f[j][t]==1)
			{
				d[j]=e[j][t];
				pri(j);
			}
		}
	}
	else
	{
		for(int j=1;j<=(2*m+n);j++)
		{
			if(f[t][j]==1)
			{
				d[j]=e[t][j]+d[t];
				pri(j);
			}
			else if(f[j][t]==1)
			{
				d[j]=e[j][t]+d[t];
				pri(j);
			}
		}		
	} 
}
int main()
{
	freopen("subway.in","r","stdin");
	freopen("subway.out ","w","stdout"); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i][i+m];
		f[i][i+m]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>a1>>b1;
			e[m+a1][2*m+i]=b1;
			f[m+a1][2*m+i]=1;
		}
	}
	int d[2*m+n+5];
	for(int i=1;i<=(2*m+n);i++)
		d[i]=-1;
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=2*m+n;j++)
			d[j]=-1;
		cin>>a>>b;
		pri(a);
		cout<<d[b];
	}
	return 0;
} 