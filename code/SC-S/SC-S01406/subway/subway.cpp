#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500100],k[500100],a[6010][6010],t[6010][6010];
int dis[6010][6010];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<=6000;i++){
		for(int j=0;j<=6000;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<=j;p++){
				if(a[i][j-p]!=0){
					dis[a[i][j]][a[i][j-p]]=dis[a[i][j-p]][a[i][j]]=min({t[i][j]+t[i][j-p],dis[a[i][j]][a[i][j-p]],dis[a[i][j-p]][a[i][j]]});
				}
				if(a[i][j+p]!=0){
					dis[a[i][j]][a[i][j+p]]=dis[a[i][j+p]][a[i][j]]=min({t[i][j]+t[i][j+p],dis[a[i][j]][a[i][j+p]],dis[a[i][j+p]][a[i][j]]});
				}
			}
			
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}