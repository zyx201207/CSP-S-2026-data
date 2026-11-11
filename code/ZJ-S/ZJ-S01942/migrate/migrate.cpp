#include <bits/stdc++.h>
using namespace std;
#define fre
//~ #define CALC

namespace zyc{
	#define rep(i,l,r) for(int i=(l);i<=(r);i++)
	#define per(i,r,l) for(int i=(r);i>=(l);i--)
	#define pb push_back
	typedef long long ll;
	const int N=2e6+5,M=305;
	int n;
	ll d,x[N],ans;
	int dp[M][M],cnt[M][M];
	
	void run(){
		memset(dp,0x3f,sizeof dp);
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n>>d;
		rep(i,1,n)cin>>x[i];
		rep(l,1,n){
			dp[l][l]=0;
			cnt[l][l]=1;
			rep(r,l+1,n){
				rep(k,l,r-1){
					if(x[r]-x[k]<=d){
						dp[l][r]=dp[l][k]+1;
						break;
					}
				}
				rep(k,l,r-1){
					if(x[r]-x[k]<=d){
						if(dp[l][r]==dp[l][k]+1)cnt[l][r]+=cnt[l][k];
					}
				}
				if(cnt[l][r]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	ll runA(){
		cin>>n>>d;
		rep(i,1,n)cin>>x[i];
		if(n<=3)return 0;
		ll del=x[2]-x[1];
		if(del*2>d)return 0;
		del=d/del;
		del=del*2;
		return max(0ll,n-del+1);
	}
	int main(){
		int c,t;
		cin>>c>>t;
		if(c==11||c==12){
			while(t--)cout<<runA()<<'\n';
		}
		else while(t--)run();
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef fre
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	zyc::main();
	return 0;
}
