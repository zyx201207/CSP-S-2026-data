#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+7;
int c,n,m,d,q;
int w[N];
int a[N][1003],t[N][1003];
int g[1003][1003],dis[1003][1003];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int qwe=1;qwe<=k;qwe++){
				if(j!=qwe){
					int u=a[i][j];
					int v=a[i][qwe];
					g[u][v]=1;
					g[v][u]=1;
					dis[u][v]=t[i][u]+t[i][v];
					dis[v][u]=t[i][u]+t[i][v];
				}
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
2 3

*/
