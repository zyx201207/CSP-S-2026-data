#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[125005],a[1251][1251],t[1255][1251],k[505],lin[5005][5005];
struct zhan{
	int x,y,w;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(lin,0x3f3f,sizeof(lin));
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	int v=0;
	for(int t=0;t<n+m;t++)
	{
		lin[t][t]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			lin[n+a[i][j]-1][i]=t[i][j];
			lin[i][n+a[i][j]-1]=t[i][j];
			v++;
		}
	}
	for(int i=0;i<n+m;i++)
	{
		for(int x=0;x<n+m;x++)
		{
			for(int y=0;y<n+m;y++)
			{
				lin[x][y]=min(lin[x][i],lin[i][y])+t[x][y];
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<lin[x+n][y+n]+w[x-1]+w[y-1]<<endl;
	}
	return 0;
}
