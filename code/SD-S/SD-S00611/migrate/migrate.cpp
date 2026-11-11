#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N1=2e6+10,N2=500,inf=1e8+10;
int n,c,t,d;
int x[N1],f[N2][N2],dis[N2][N2],sum[N2];
void init(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dis[i][i]=0;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>c>>t;
	while(t--){
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++){
			cin>>x[i];
			sum[i]=sum[i-1]+x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x[i+1]-x[i]<=d){
				dis[i][i+1]=1;
				f[i][i+1]=1;
			}
			else{
				dis[i][i+1]=inf;
				f[i][i+1]=0;
			}
		}
		for(int len=2;len<=n;len++){
			for(int u=1,v=u+len-1;v<=n;v++,u++){
				if(x[v]-x[u-1]<=d){
					dis[u][v]=dis[v][u]=1;
					f[u][v]=f[v][u]=1;
					continue;
				}
				for(int k=u+1;k<=v-1;k++){
					if(x[k]-x[u]>d)  continue; 
					if(f[u][k]==inf||f[k][v]==inf) continue;
					if(dis[u][v]==dis[u][k]+dis[k][v]){
						 f[u][v]+=f[u][k]*f[k][v];
					}else if(dis[u][v]>dis[u][k]+dis[k][v]){
						f[u][v]+=f[u][k]*f[k][v];
						dis[u][v]=dis[u][k]+dis[k][v];
					}
				}
				if(f[u][v]==2&&dis[u][v]!=inf)   ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

