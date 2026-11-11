#include<bits/stdc++.h>
using namespace std;
long long INF=1e8+100;
long long c,n,m,d,q,x,y;
long long ans;
int w[500050];
long long xxx[1210][1210];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
for(int i=1;i<=n+m;i++){
	for(int j=1;j<=n+m;j++){
		xxx[i][j]=INF;
			
	}
}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>c>>ans;
			xxx[c][i+m]=ans;
		//cout<<"s"<<xxx[c][i+m]<<endl;
			xxx[i+m][c]=ans;
	    }
	}
	
for(int k=1;k<=n+m;k++){
	for(int j=1;j<=n+m;j++){
		for(int i=1;i<=n+m;i++){
			if(xxx[i][j]>xxx[i][k]+xxx[k][j]){
			xxx[i][j]=xxx[i][k]+xxx[k][j];
			}
			
			
		}
	}
}
	while(q--){
		cin>>x>>y;
		//cout<<"s"<<xxx[x][y]<<endl;
		cout<<w[x]+w[y]+xxx[x][y]<<endl;
	}
	
	return 0;
}
