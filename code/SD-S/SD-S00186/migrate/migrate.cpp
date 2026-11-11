#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e6+5;
int c,T,n,dp[N],cnt[N];
ll d,a[N],ans;
void solve_1(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dp[i]=0;
			cnt[i]=1;
			for(int j=i+1;j<=n;j++){
				dp[j]=N;
				cnt[j]=0;
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]<=d){
						if(dp[k]+1<dp[j]){
							dp[j]=dp[k]+1;
							cnt[j]=cnt[k];
						}else if(dp[k]+1==dp[j]){
							cnt[j]=min(cnt[j]+cnt[k],3);
						}
					}
				}
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	solve_1();
	return 0;
}
