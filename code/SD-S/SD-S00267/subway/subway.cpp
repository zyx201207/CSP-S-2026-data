#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a1[500005], c,n,m,d,q;;
int a[5505][5505];
bool state[505];
void di()
{
	for(int t=n+m;t>=1;t--)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][t]!=INT_MAX&&a[t][j]!=INT_MAX&&(a[i][j]>a[i][t]+a[t][j]))
				{
					a[j][i]=a[i][j]=a[i][t]+a[t][j];
				}	
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a1[i];
	}
	for(int i=1;i<=m+n;i++)
	{
		for(int j=1;j<=m+n;j++)
		{
			a[i][j]=INT_MAX;
			if(i==j) a[i][j]=0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x][m+i]=y;
			a[m+i][x]=y;
		}
	}
	di();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<a[x][y]+a1[x]+a1[y]<<endl;
	}
	return 0;
 } 
 
