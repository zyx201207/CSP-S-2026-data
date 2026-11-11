#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,M=5000;
int n,dd;
int a[N];
int v[M][M],d[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>dd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				v[i][j]=0;
				d[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>dd) break;
				v[i][j]=v[j][i]=j-i+1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(v[i][j]||!v[i][k]||!v[k][j]||i==j||j==k||i==k) continue;
					v[i][j]=v[j][i]=v[i][k]+v[k][j]-1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(!v[i][j]||!v[i][k]||!v[k][j]||i==j||j==k||i==k) continue;
					if(v[i][j]==v[i][k]+v[k][j]-1){
						d[i][j]++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]==2) ans++;
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
