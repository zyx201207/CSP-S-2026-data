#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+10;
int a[N];
int dis[404][404];
int f[404][404];
void solve1(){
	while(t--){
		int n,d;
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=2e18,f[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			cin >>a[i];
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) dis[i][j]=dis[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){ 
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(i==j||k==i||k==j) continue;
					if(dis[i][k]+dis[k][j]<dis[i][j]) f[i][j]=1;
					else if(dis[i][k]+dis[k][j]==dis[i][j]) f[i][j]++;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		int ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				//cout <<f[u][v]<<" "<<u<<" "<<v<<endl;
				if(f[u][v]==2||f[v][u]==2) ans++;
			}
		}
		cout <<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>c>>t;
	if(c<=6){
		solve1();
	}
	else if(c>=11&&c<=12){
		while(t--){
			int n,d;
			cin >>n>>d;
			for(int i=1;i<=n;i++){
				cin >>a[i];
			}
			int dc=a[2]-a[1];
			if(dc>=d||n<=2) cout <<0<<endl;
			else{
				int uy=d/dc;
				uy=uy+uy-1;
				cout <<max(n-uy,0ll)<<endl;
			}
		}
	}
	else{
		while(t--){
			int n,d;
			cin >>n>>d;
			for(int i=1;i<=n;i++){
				cin >>a[i];
			}
			cout <<0<<endl;
		}
	}
	return 0;
}

