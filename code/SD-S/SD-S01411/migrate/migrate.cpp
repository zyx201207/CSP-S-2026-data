#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,d;
int x[N];
int f[310][310];
int cnt[310][310];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=1e9,cnt[i][j]=0;
				if(x[j]-x[i]<=d){
					f[i][j]=1;
					cnt[i][j]=1;
				}
			}
		}
		for(int k=2;k<n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<=n;j++){
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(f[i][k]+f[k][j]==f[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
