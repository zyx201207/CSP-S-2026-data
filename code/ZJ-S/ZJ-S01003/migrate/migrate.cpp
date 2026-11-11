#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,t,ans;
int n;
ll d,x[N];
int dp[N],cs[N];
void solve(int pp){
	memset(dp,0,sizeof(dp));
	memset(cs,0,sizeof(cs));
	dp[pp]=1;
	cs[pp]=0;
	for(int i=pp;i<=n;i++){
		for(int j=pp;j<i;j++){
			if(x[i]-x[j]>d) continue; 
			if(x[i]-x[j-1]<=d&&cs[j]>cs[j-1]) break;
			dp[i]+=dp[j];
			cs[i]=cs[j]+1;
		}
		if(dp[i]==2) ans++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) solve(i);
		cout<<ans<<"\n";
	}
	return 0;
}
