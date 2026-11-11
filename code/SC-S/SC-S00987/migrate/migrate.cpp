#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5005;
int c,t;
ll a[N],g[N][N],way[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		memset(a,0,sizeof(a));
		memset(g,0x3f,sizeof(g));
		memset(way,0,sizeof(way));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					g[i][j]=0;
					way[i][j]=1;
					continue;
				}
				if((ull)abs(a[i]-a[j])<=d){
					g[i][j]=1;
					g[j][i]=1;
					way[i][j]=1;
					way[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(k==i||k==j){
						continue;
					}
					if(g[i][j]>g[i][k]+g[k][j]){
						g[i][j]=g[i][k]+g[k][j];
					}
					else if(g[i][j]==g[i][k]+g[k][j]){
						way[i][j]+=1;
						way[j][i]+=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j){
					continue;
				}
				if(way[i][j]==2){
					ans+=1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}