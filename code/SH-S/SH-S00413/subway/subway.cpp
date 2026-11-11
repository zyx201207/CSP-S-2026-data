#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int w[500005],a[505][1005],t[505][1005];
long long f[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				f[a[i][u]][a[i][v]]=min(f[a[i][u]][a[i][v]],(long long)t[i][u]+t[i][v]);
				f[a[i][v]][a[i][u]]=min(f[a[i][v]][a[i][u]],(long long)t[i][u]+t[i][v]);
			}
		}    
	}                                                                                              
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				for(int s=1;s<=m;s++){
					if(s!=i && s!=j) f[i][j]=min(f[i][j],f[i][s]+f[s][j]);
				}                       
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
