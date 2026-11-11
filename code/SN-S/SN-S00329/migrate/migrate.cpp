#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000
#define bcstr basic_string
#define i128 __int128
using namespace std;
int qx,T,n,d;
int a[2000005],r[2000005];
int dp[2000005],cnt[2000005];
map<int,int> mp;
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) r[i]=upper_bound(a+i,a+1+n,a[i]+d)-a-1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) dp[j]=INF,cnt[j]=0;
		dp[i]=0,cnt[i]=1;
		mp.clear(),mp[0]++;
		for(int j=i-1;j>0;j--){
			int p=min(i,r[j]),pp=min(i,r[j+1]);
			for(int k=p+1;k<=pp;k++){
				mp[dp[k]]-=cnt[k];
				if(mp[dp[k]]==0) mp.erase(dp[k]);
			}
			dp[j]=mp.begin()->first+1,cnt[j]=mp.begin()->second;
			mp[dp[j]]+=cnt[j];
		}
		for(int j=1;j<i;j++) if(cnt[j]==2) ans++;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) a[i]=r[i]=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>qx>>T;
	while(T--) work();
	return 0;
}
