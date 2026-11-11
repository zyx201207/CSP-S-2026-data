#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;

int c,t,n,d,x[N],f[N][N],vis[N][N],ans;
void floyd(){
	for(int z=1;z<=n;z++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][z]+f[z][j]);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)f[i][j]=1;
				else f[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int zhi=abs(x[i]-x[j]);
				if(zhi<=d){
					f[i][j]=f[j][i]=1;
				}
			}
		}
		floyd();
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][k]+f[k][j]==f[i][j]){
						vis[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(vis[i][j]>1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	


	return 0;
}

