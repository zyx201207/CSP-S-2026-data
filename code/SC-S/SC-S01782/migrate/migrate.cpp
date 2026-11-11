#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
ll c,t;
ll x[N],f[N][N];
ll vis[N][N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		memset(vis,0,sizeof vis);
		memset(f,0x3f,sizeof f);
		ll n,d,cnt=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				ll k=abs(x[i]-x[j]);
				if(k<=d) f[i][j]=f[j][i]=1;
			}
				
		
		for(ll k=1;k<=n;k++){
			for(ll i=1;i<=n;i++){
				if(i==k) continue;
				for(ll j=1;j<=n;j++){
					if(j==i||j==k) continue;
					if(f[i][j]==f[i][k]+f[k][j]){
						vis[i][j]++;
						vis[j][i]++;
					}
					else if(f[i][j]>f[i][k]+f[k][j]){
						vis[i][j]=vis[j][i]=1;
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(vis[i][j]==3) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}