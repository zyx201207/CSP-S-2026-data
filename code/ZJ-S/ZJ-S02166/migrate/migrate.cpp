#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=2e6+5;
ll _C,_T;
ll n,d;
ll a[N];
ll f[15][15];
ll cnt[15][15];
ll l,r;
void dfs(int x, int k){
	if(x==r){
		if(k==f[l][r]) cnt[l][r]++; return;
	}
	for(int i=x+1;i<=n;i++) if(a[i]-a[x]<=d) dfs(i,k+1);
}
ll ans;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		int lst=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[lst]<=d&&a[j+1]-a[lst]>d||j==n){
				f[i][j]=f[i][lst]+1;
				lst=j;
			}
		}
		for(int j=n;j>i;j--) if(f[i][j]==0) f[i][j]=f[i][j+1];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++) cout<<i<<" - "<<j<<" : "<<f[i][j]<<endl;
//	}
	
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			l=i;
			r=j;
			dfs(i,0);
		}
	}
	ans=0;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) ans+=cnt[i][j]==2;
	cout<<ans<<'\n';
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_C>>_T;
	while(_T--) solve();
	return 0;
}
