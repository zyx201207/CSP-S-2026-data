#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int c,n,m,d,q,w[N],k[N],t[N],u[N],b[N][N],vis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>u[j]>>t[j];
			for(int l=1;l<j;l++)
			{
				vis[u[l]][u[j]]=min(t[l]+t[j],vis[u[l]][u[j]]);
				vis[u[j]][u[l]]=min(t[l]+t[j],vis[u[j]][u[l]]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=1;l<=m;l++)
			{
				if(vis[i][j]>vis[i][l]+vis[l][j])
				{
					vis[i][j]=vis[i][l]+vis[l][j];
				}
			}
		}
	}

	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+vis[x][y]<<endl;
	}
	return 0;
}

