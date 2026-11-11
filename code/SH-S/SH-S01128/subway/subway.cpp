#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll w[500005];
ll a[505][50005];
ll dis[5005][5005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f3f3f3f3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		dis[i][i] = 0;
	}
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int cnt;cin>>cnt;
		if (cnt==2){
			ll x1,x2,x3,x4;cin>>x1>>x2>>x3>>x4;
			dis[x1][x3] = x2+x4;
			dis[x3][x1] = x2+x4;
		}
		else{
			for (int j=1;j<=cnt;j++){
				int u;cin>>u;
				cin>>a[i][u]; 
			}
		}	
	}
	if (c<=6||c>11){
		for (int k=1;k<=n;k++){
			for (int i=1;i<=m;i++){
				for (int j=i+1;j<=m;j++){
					if (a[k][i]!=0&&a[k][j]!=0){
						dis[i][j] = a[k][i]+a[k][j];
						dis[j][i] = a[k][i]+a[k][j];
					}
				}
			}
		}
	}
	for (int k=1;k<=m;k++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<endl;
	}
	return 0;
} 
