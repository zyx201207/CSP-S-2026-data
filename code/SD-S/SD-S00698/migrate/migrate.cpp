#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int maxn=2e6+7;
int c,T,n,d;
int x[maxn],cnt[maxn],dp[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		f(i,1,n){
			cin>>x[i];
		}
			int ans=0;
			f(k,1,n){
				f(i,1,n){
					cnt[i]=0;
					dp[i]=1e9;
				}
				dp[k]=0;
				f(i,k+1,n){
					f(j,k,i-1){
				//	cout<<k<<i<<j<<endl;
						if(x[i]-x[j]<=d){
							if(dp[i]>dp[j]+1){
								dp[i]=min(dp[j]+1,dp[i]);
								cnt[i]=max(cnt[j],1LL);
							}
							else if(dp[i]==dp[j]+1){
								cnt[i]+=cnt[j];
							}
						}
					}
					if(cnt[i]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
	}
	return 0;
}



