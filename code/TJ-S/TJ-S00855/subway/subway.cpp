#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[1005],k[1005],a[1005][1005],t[1005][1005],dt[1005][1005],dis[1005][1005];
void solver1(){
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			dis[i][j]=1e9;
		}
		dis[i][i]=0;
	}
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			dis[a[i][j]][m+i]=0;
			dis[m+i][a[i][j]]=0;
			dt[a[i][j]][0]++;
			dt[a[i][j]][dt[a[i][j]][0]]=i;
			for(int l=1;l<dt[a[i][j]][0];l++){
				dis[m+dt[a[i][j]][l]][m+i]=min(dis[m+dt[a[i][j]][l]][m+i],t[i][a[i][j]]+t[dt[a[i][j]][l]][a[i][j]]);
				dis[m+i][m+dt[a[i][j]][l]]=min(dis[m+i][m+dt[a[i][j]][l]],t[i][a[i][j]]+t[dt[a[i][j]][l]][a[i][j]]);
			}
		}
	}
	for(int l=m+1;l<=m+n;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	solver1();
	return 0;
}
