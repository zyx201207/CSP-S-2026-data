#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=130005;
ll c,n,m,d,q,w[N],k[N],a[N][M],t[N][M],u,v;
ll p[M][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			p[i][j]=0x3f3f3f3f;
			if(i==j){
				p[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			t[j][i]=t[i][j];
			if(j>1){
				p[a[i][j-1]][a[i][j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]==0){
				for(int k=1;k<=m;k++){
					if(p[j][k]==0){
						p[i][k]=min(p[i][k],t[i][j]+t[j][k]);
					}
				} 
			} 
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(p[i][k]!=0x3f3f3f3f){
				for(int j=1;j<=m;j++){
					if(p[k][j]!=0x3f3f3f3f){
						if(p[i][k]+p[k][j]<p[i][j]){
							p[i][j]=p[i][k]+p[k][j];
						}
					}
				}
			}
		}
	}
	while(q--){
		cin>>u>>v;
		cout<<w[u]+w[v]+p[u][v];
	}
	return 0;
}  
