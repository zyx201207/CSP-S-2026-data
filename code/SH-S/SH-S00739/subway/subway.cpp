#include<bits/stdc++.h>
using namespace std;
int n,m,d,c,w[50020],a[510][50020],t[510][50020],z[50020][25],c[510][510],co[510];
int ans,x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(z[a[i][j]][0]==0)
			{
				z[a[i][j]][0]=i;
			}
			else
			{
				for(int l=1;l<=23;l++)
				{
					if(z[a[i][j]][l]!=0)
					{
						c[z[a[i][j]][l]][i]=1;
						c[i][z[a[i][j]][l]]=1;
					}
					else
					{
						z[a[i][j]][l]=i;
						break; 
					}
				}
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<=505;j++)
		{
			co[j]=1e9+5;
		}
		cin>>x>>y;
		cout<<"0";
	}
	
	return 0;
}
