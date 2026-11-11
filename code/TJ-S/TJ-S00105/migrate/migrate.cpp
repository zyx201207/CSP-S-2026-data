#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
const ll INF = 2e18;
ll x[N],dp[N],dis[N];
void solve1(){
	int n;
	ll d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n<=3) {
		cout<<0<<'\n';
		return ;
	}
	for(int st=1;st<=n;st++){
		for(int i=1;i<=n;i++) {
			dis[i]=INF;
			dp[i]=0;
		}
		dis[st]=0;
		for(int i=st;i<=n;i++){
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				if(dis[j]>dis[i]+1) {
					dis[j]=dis[i]+1;
					dp[j]=1;
				}else if(dis[j]==dis[i]+1){
					dp[j]++;
				}
			}
		}
		for(int i=1;i<=n;i++) if(dp[i]==2) ans++;
	}
	
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; 
	cin>>c>>t;
	while(t--){
		solve1();
	}
	return 0; 
}

