#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[2000005],dp[2000005];
ll vis[2000005];
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=m;i++){dp[i]=0;}
		for(int l=m+1;l<=n;l++){
			dp[l]=0;
			memset(vis,0,sizeof vis);
			int cnt=0;
			ll k=l;
			while(k-m>=0){
				vis[++cnt]=m;
				k-=m;
			}
			if(k!=0){
				vis[++cnt]=k;
			}
			bool f=0;
			for(int i=1,j=cnt;i<=cnt,j>=1;i++,j--){
				if(vis[i]!=vis[j]){
					dp[l]+=1;
					break;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=dp[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

