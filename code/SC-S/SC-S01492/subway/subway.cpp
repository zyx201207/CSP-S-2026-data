#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+1];
	for(int i=1;i<=m;i++) cin>>w[i];
	int tot=m+n;
	int dis[105][105];
    for(int i=1;i<=tot;i++) {
    	for(int j=1;j<=tot;j++){
    		dis[i][j]=1e9;
		}
		dis[i][i]=0;
	}
    for(int i=1;i<=n;i++){
    	int k,l=m+i,a;
    	int t;
    	cin>>k;
    	while(k--){
    		cin>>a>>t;
    		dis[a][l]=min(dis[a][l],t);
    		dis[l][a]=min(dis[l][a],t);
		}
	}
	for(int k=1;k<=tot;k++){
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=tot;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<endl;
	}
	return 0;
}