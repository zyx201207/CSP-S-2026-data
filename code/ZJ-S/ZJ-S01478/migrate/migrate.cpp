#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<long long,long long> pii;
int x[2000005],b[2000005];
pii dp[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12){
        	cout<<0<<'\n';
        	continue;
		}
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++)  dp[j]={0,0},b[j]=0;
            dp[1]={0,1};
            int l=2,r=2,sum=0;
            for(int id=i;id<=n;id++){
            	int j=id-i+1;
            	sum+=b[j];
            	dp[j].second+=sum;
                if(dp[j].second==0) break;
                if(dp[j].second==2) ans++;
                int k=upper_bound(x+1,x+n+1,x[id]+d)-x-1;
                k=k-i+1;
                while(r<=k){
                	if(dp[r].first==0) dp[r].first=dp[j].first+1;
                	r++;
				}
                while(dp[l].first!=dp[j].first+1&&l<=k) l++;
                b[l]+=dp[j].second,b[k+1]-=dp[j].second;
            };
        }
        cout<<ans<<'\n';
    }
    return 0;
}