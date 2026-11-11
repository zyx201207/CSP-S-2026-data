/*
问每个点对(u,v)是否满足uv之间有且仅有两条最短路径
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e6;
ll c,T;
ll n,d;
ll x[N];
ll dp[N],cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll ans=0;
		for(int s=1;s<=n;s++){
			memset(dp,0x3f,sizeof dp);
			memset(cnt,0,sizeof cnt);
			dp[s]=0;
			for(int i=s;i<=n;i++){
				for(int j=i;j>=s;j--){
					if(x[i]-x[j]<=d){
						if(dp[i]>dp[j]+1){
							cnt[i]=1;
							dp[i]=dp[j]+1;
						}else if(dp[i]==dp[j]+1){
							cnt[i]++;
						}
					}else{
						break;
					}
				}
			}
			for(int i=s;i<=n;i++)ans+=(cnt[i]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}