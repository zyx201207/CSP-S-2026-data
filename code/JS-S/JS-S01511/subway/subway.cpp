#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[20005],a[500][20005],t[500][20005],k[20005],x,y,ans=0,cost[500][500],cm[500][500];//m ge zhan(500000) ,n tiao xian(500) ,
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cost[i][j]=INT_MAX;
			cost[j][i]=INT_MAX;
		}
	}

	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];

		}
	}
	//if(c==20||c==21){

		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
                    for(int kk=1;kk<j;kk++){

					long long u=a[i][kk],v=a[i][j];
					long long uv=t[i][j]+t[i][kk];
					cost[u][v]=min(uv,cost[u][v]);
					cost[v][u]=min(uv,cost[v][u]);

				}
			}
		}

		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){

					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
					cost[j][i]=min(cost[j][i],cost[j][k]+cost[k][i]);
				}
			}
		}
		while(q--){
		cin>>x>>y;
		cout<<cost[x][y]+w[x]+w[y]<<endl;
		}

   return 0;
}
