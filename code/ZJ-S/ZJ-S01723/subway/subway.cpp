#include <bits/stdc++.h>
using namespace std;
const int N=510; 
int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N],f[N][N],ti[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int o;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j==1){
				o=a[i][j];continue;
			}
			ti[o][a[i][j]]=t[i][a[i][j]]+t[i][o];
			f[o][a[i][j]]=1;
			o=a[i][j];
		}
	}
//	for(int i=1;i<=m;i++) ti[i][i]=w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) f[i][j]=0,ti[i][j]=w[i];
			else if(f[i][j]==1) continue;
			else f[i][j]=1e9;
			if(ti[i][j]!=0) ti[i][j]=1e9;
		}
	}		
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]!=1e9 && f[i][k]!=1e9 && f[k][j]!=1e9){
					if(ti[i][j]>ti[i][k]+ti[k][j]){
						ti[i][j]=t[i][k]+ti[k][j];
						f[i][j]=f[i][k]+f[k][j];
					}
					else ti[i][j]=ti[i][j];
				}
				else{
					if(f[i][j]>f[i][k]+f[k][j]){
						ti[i][j]=ti[i][k]+ti[k][j];
						f[i][j]=f[i][k]+f[k][j];
					}
					else ti[i][j]=ti[i][j];
				}
			}
		}
	}	
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(f[x][y])
		cout<<w[x]+ti[x][y]+w[y]<<endl;
	}
	return 0;
}
