#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int dis[N][N];
int n,k;
int ss(int x){
	int cnt=0;
	while(x){
		if(x&1) cnt++;
		x>>=1;
	}return cnt;
}
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>k;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			dis[u][v]=dis[v][u]=1;
		}Floyd();
		int zx=n;
		for(int i=0;i<(1<<n);i++){
			if(ss(i)!=k) continue;
			int p=0;
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(i&(1<<j)||!(i&(1<<k))) continue;
					p=max(p,dis[j+1][k+1]);
				}
			}zx=min(zx,p); 
		}cout<<zx-2<<"\n";
	}
	return 0;
}
