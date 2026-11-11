#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=1000;
long long ans,c[N][N],x[N][N];
int cc,n,m,d,T,w[M],k[N],z[M],a,t,tg[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	cin>>cc>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			z[a]++;
			x[a][z[a]]=t;
			tg[a][z[a]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=z[i];j++){
			for(int k=i;k<=z[i];k++){
				c[j][k]=min(x[i][j]+x[i][k],c[j][k]);
				c[k][j]=c[j][k];
		}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
		}
		}
	}
	for(int i=1;i<=n;i++)
		c[i][i]=0;
	
	while(T--){
		int xx,yy;
		cin>>xx>>yy;
		ans=1e18;
		for(int i=1;i<=z[xx];i++){
			for(int j=1;j<=z[yy];j++){
				
				ans=min(ans,c[tg[xx][i]][tg[yy][i]]+x[xx][i]+x[yy][j]);
			}	
		}
		cout<<ans+w[xx]+w[yy]<<endl;
	}
}
