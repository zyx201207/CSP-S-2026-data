#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[500010],k[510];
int a[510][50010],t[510][50010];
int dis[1010][1010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int u=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			u++;
			dis[a[i][j]][u]=t[i][j];
			dis[u][a[i][j]]=t[i][j];
			if(j>1)dis[u-1][u]=0,dis[u][u-1]=0;
		}
	}
	for(int i=1;i<=u;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=u;i++){
		for(int s=1;s<=u;s++){
			for(int t=1;t<=u;t++){
				dis[s][t]=min(dis[s][t],dis[s][i]+dis[i][t]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dis[s][t]+w[s]+w[t]<<endl; 
	}
	return 0;
}
