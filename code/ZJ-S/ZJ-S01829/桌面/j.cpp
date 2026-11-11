#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=500000000001;
int w[501],alen[501],a[501][1001],qu[100001][2];
int di[501][501],f[501][501],e[501][501];
int c,n,m,d,q;
void A()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			di[i][j]=INF;
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=alen[i];j++)
			for(int k=j+1;k<=alen[i];k++)
			{
				int p1=a[i][2*j-1],p2=a[i][2*k-1],w1=a[i][2*j],w2=a[i][2*k];
				if(w1+w2<di[p1][p2])
				{
					di[p1][p2]=w1+w2;
					di[p2][p1]=w1+w2;
				}
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=di[i][j];
			f[j][i]=di[i][j];
		}
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(f[i][j]+f[j][k]<f[i][k])
					f[i][k]=f[i][j]+f[j][k];
	for(int i=1;i<=q;i++)
	{
		int x,y;
		x=qu[i][0],y=qu[i][1];
		int ans=f[x][y]+w[x]+w[y];
		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
		di[i][i]=0;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>alen[i];
		for(int j=1;j<=2*alen[i];j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=q;i++)	
		cin>>qu[i][0]>>qu[i][1];
	A();
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=alen[i];j++)
			cout<<a[i][2*j-1]<<" "<<a[i][2*j]<<'\n';
		cout<<'\n';
	}*/
	
	
	
	//for(int i=1;i<=n;i++)
	//	for(int j=i+1;j<=n;j++)	
	//		cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
	return 0;
}
