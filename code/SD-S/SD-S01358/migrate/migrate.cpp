#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll N=3e2+5,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll t,n,d,a[N],f[N][N];
int main(){
	freopen("migrate.in","r",stdin);
  	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					f[i][j]=1;
				}else f[i][j]=INF;
				if(i==j) f[i][j]=0;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll si=0;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[i]<=d){
						if(f[i][k]+f[k][j]==f[i][j]){
							si++;
							if(si>2) break;
						}
					}else break;
				}
				if(si==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}


	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
