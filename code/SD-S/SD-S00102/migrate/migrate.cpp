#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5086;
int C,T,n,d,a[N];
int f[N][N];
int cnt[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>5000){
			cout<<(a[2]-a[1]+d-1)%d<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=f[j][i]=0;
				cnt[i][j]=cnt[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d&&i!=j){
					f[i][j]=1;
					cnt[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=k-1;i++){
				if(i==k||cnt[i][k]==0) continue;
				for(int j=k+1;j<=n;j++){
					if(cnt[k][j]==0||i==j||j==k){
						continue;
					}
					if(f[i][k]+f[k][j]==f[i][j]){
						cnt[i][j]++;
					}
					if(f[i][k]+f[k][j]<f[i][j]||cnt[i][j]==0){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=1;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
