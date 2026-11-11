#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[5009];
int e[5009][5009];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					e[i][j]=1e9;
				}
			}
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]+d>=a[j]){
						e[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<e[i][j]<<endl;
					int cnt=0;
					for(int k=1;k<=n;k++){
						if(e[i][j]==e[i][k]+e[k][j]){
							cnt++;
							//cout<<i<<" "<<j<<" "<<k<<endl;
						}
					}
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
