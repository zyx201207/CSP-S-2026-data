#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10010;
const ll N1=2e9+10;
ll c,t;
ll n,d;
ll jk[N][N];
ll f[N][N];
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		ll cnt=0;
		memset(jk,N1,sizeof jk);
		memset(f,0,sizeof f);
		for(ll i=1;i<=n;i++){
			cin >> x[i];
			jk[i][i]=0;
			f[i][i]=1;
			for(ll j=i-1;j>=1;j--){
				if(x[i]-x[j] <= d){
					jk[j][i]=1;
					f[j][i]=1;
				} 
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				for(ll k=i+1;k<=j-1;k++){
					if(f[i][k]>=1 && f[k][j]>=1){
						if(jk[i][k]+jk[k][j] < jk[i][j]){
							jk[i][j]=jk[i][k]+jk[k][j];
							f[i][j]=1;
						}
						else if(jk[i][k]+jk[k][j] == jk[i][j]){
							f[i][j]++;
						}
					}
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(f[i][j]==2) ++ cnt;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
