#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[605],f[605][605][605],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		memset(f,0,sizeof(f));
		ans=0;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				int now=ceil(1.0*(x[j]-x[i])/d);
				for (int k=i+1;x[k]<=x[i]+d&&k>=x[j]-d&&k<=j;k++){
					f[i][j][now]=max(f[i][j][now],f[i][k][now-1]+1);
				}
				if (f[i][j][now]==2){
					ans++;
				}
			}
			
		}
		cout << ans<<"\n";
	}
	
	return 0;
}
