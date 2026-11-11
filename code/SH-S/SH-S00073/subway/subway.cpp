#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll dis[15003][15003],di[503];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>di[i];
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=1000000000000000000;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>dis[a][m+i];
			dis[m+i][a]=dis[a][m+i];
		}
	}
	for(int i=1;i<=n+m;i++)dis[i][i]=0;
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=i+1;j<=n+m;j++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<di[x]+di[y]+dis[x][y]<<'\n';
	}
	return 0;
}
