#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q,a[1005],dis[1505][1505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	{
		int c; cin>>c;
	}
	cin>>n>>m>>d>>q;
	for (int i=1;i<=n+m;i++)
		dis[i][i]=0;
	for (int i=1;i<=m;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		int k; cin>>k;
		for (int j=1;j<=k;j++){
			int x,t; cin>>x>>t;
			dis[x][m+i]=dis[m+i][x]=t;
		}
	}
	for (int k=1;k<=n+m;k++){
		for (int i=1;i<=n+m;i++){
			for (int j=1;j<=n+m;j++){
				if (i!=j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		int x,y; cin>>x>>y;
		cout<<dis[x][y]+a[x]+a[y]<<"\n";
	}
	return 0;
}
