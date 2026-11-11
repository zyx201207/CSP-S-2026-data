#include<bits/stdc++.h>
using namespace std;
long long ev[500010][22];
long long ew[500010][22];
long long sz[500010];
const long long INF=1e18;
long long dis[510][510];
long long cw[500010];
long long cc,n,m,d,qq;
inline void add(long long &x,long long y){
	x=min(x,y);
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>cc>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>cw[i];
	for(int i=1;i<=n;i++){
		long long k;cin>>k;dis[i][i]=0;
		while(k--){
			long long x,y;cin>>x>>y;
			sz[x]++;ev[x][sz[x]]=i;ew[x][sz[x]]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sz[i];j++){
			for(int k=j+1;k<=sz[i];k++){
				add(dis[ev[i][j]][ev[i][k]],ew[i][j]+ew[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
			
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue; 
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(qq--){
		long long x,y,ans=INF;cin>>x>>y;
		for(int j=1;j<=sz[x];j++){
			for(int k=1;k<=sz[y];k++){
				ans=min(ans,dis[ev[x][j]][ev[y][k]]+cw[x]+cw[y]+ew[x][j]+ew[y][k]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}