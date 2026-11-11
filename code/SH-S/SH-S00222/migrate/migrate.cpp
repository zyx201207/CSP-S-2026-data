#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=2e6+5;
int c,t,n;
ll d;
ll x[N];
int pl[N],pr[N];
int f[N];
int dp[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		fill(pl,pl+n+1,0);
		fill(pr,pr+n+1,0);
		fill(f,f+n+1,0);
		fill(dp,dp+n+1,0);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int l=1;
		for(int r=1;r<=n;r++){
			while(x[r]-x[l]>d){
				pr[l]=r-1;
				l++;
			}
			pl[r]=l;
		}
		for(int i=l;i<=n;i++) pr[i]=n;
		for(int i=1;i<=n;i++){
			if(pr[i]>i) f[pr[i]]+=f[i]+1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(pl[i]+1<i && pl[pl[i]+1]<pl[i]) dp[i]+=f[pl[i]+1];
			//if(pr[i]>i) dp[pr[i]]+=dp[i];
			ans+=dp[i]; 
		}
		cout<<ans<<'\n';
	}
	return 0;
}

