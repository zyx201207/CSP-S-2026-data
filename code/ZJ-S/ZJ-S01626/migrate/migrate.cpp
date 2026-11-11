#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
ll n,d;
ll f[N][N],cnt[N][N],a[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=3e18;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int j=i+1;
		while(j<=n && a[j]-a[i]<=d){
			f[i][j]=f[j][i]=1;
			cnt[i][j]=cnt[j][i]=1;
			//cout<<i<<" "<<j<<"\n";
			j++;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){ 	
			for(int j=1;j<=n;j++){
				if(i==k || j==k || i==j) continue;
				ll v=f[i][k]+f[k][j];
				if(v<f[i][j]){
					cnt[i][j]=cnt[i][k]*cnt[k][j];
					f[i][j]=v;
				}else if(v==f[i][j]){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}	
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){ 	
			for(int k=1;k<=n;k++){
				if(i==k || j==k || i==j) continue;
				ll v=f[i][k]+f[k][j];
				if(v<f[i][j]){
					cnt[i][j]=1;
					f[i][j]=v;
				}else if(v==f[i][j]){
					cnt[i][j]++;
				}
			}
		}	
	}*/
	/*
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<f[i][j]<<" ";
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<cnt[i][j]<<" ";*/
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--) solve();
	return 0;
}