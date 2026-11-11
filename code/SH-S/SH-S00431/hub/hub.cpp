#include<bits/stdc++.h>
using namespace std;
int c,t,n,K;
int P[100000];
int Find(int X){
	if(X==P[X]) return X;
	return P[X]=Find(P[X]);
}
int F[300][300],E[300][300];
bool Vis[300];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		cin>>n>>K;
		int ans=1e9;
		memset(F,0x3f,sizeof(F));
		memset(E,0x3f,sizeof(E));
		for(int i=1;i<=n;i++) F[i][i]=E[i][i]=0;
		for(int i=1,u,v;i<n;i++) cin>>u>>v,F[u][v]=F[v][u]=E[u][v]=E[v][u]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
				}
			}
		}
		for(int i=0;i<(1<<n);i++){
			int c=__builtin_popcount(i);
			if(c!=K) continue;
			c=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i) c++;
			}
			if(c!=K) continue;
			int Cnt=0;
			for(int j=1;j<=n;j++) P[j]=j;
			memset(Vis,0,sizeof(Vis));		
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					for(int k=1;k<=n;k++){
						if(E[j+1][k]==1&&((1<<(k-1))&i)) P[Find(j+1)]=Find(k);
					}
				}
			}
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					if(!Vis[Find(j+1)]) Vis[Find(j+1)]=1,Cnt++; 
				}
			}
			if(Cnt<=2){
				int Cur=0;
				for(int j=1;j<=n;j++){
					int Min=1e9;
					for(int k=0;k<n;k++){
						if((1<<k)&i) Min=min(Min,F[k+1][j]);
					}
					Cur=max(Cur,Min);
				}
				ans=min(ans,Cur);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
