#include<bits/stdc++.h>
#define int long long
#define N 5005
using namespace std;
int c,t,n,d,x[N],f[N][N],ct[N][N],ans;
void init(){
	memset(x,0,sizeof x);
	memset(f,0x3f,sizeof f);
	memset(ct,0,sizeof ct);
	ans=0;
	return;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		init(),cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int u=n;u>=1;u--){
			f[u][u]=0;
			for(int v=u+1;v<=n;v++){
				if(x[v]-x[u]<=d) f[u][v]=1;
				for(int k=u+1;k<v;k++){
					if(f[u][k]>1) break;
					f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
				}
			}
		}
		for(int u=n;u>=1;u--){
			for(int v=u;v<=n;v++){
				if(x[v]-x[u]<=d) ct[u][v]=1;
				for(int k=u+1;k<v;k++){
					if(f[u][k]>1) break;
					if(f[u][v]==f[u][k]+f[k][v]){
						ct[u][v]+=ct[k][v];
					}
					if(ct[u][v]>2) break;
				}
				if(ct[u][v]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}