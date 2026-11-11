#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
using ll=long long;
const int N=2000009,inf=1e9;
int n,dis[N],cnt[N],lft[N],rgt[N],c,t;
ll d,a[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(c<=10){
        for(int i=1;i<=n;i++){
            rgt[i]=lower_bound(a+1,a+1+n,a[i]+d+1)-a-1;
            lft[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
            cnt[lft[i]]++;
        }
        // for(int i=1;i<=n;i++) if(rgt[i]) st[i]=cnt[rgt[i]-1];
        int ans=0;
        for(int l=1;l<=n;l++){
            vector<pair<int,int> > dp(n+1);
            dp[l]={0,1};
            for(int r=l;r<=n;r++){
                int fi=max(lft[r],l);
                dp[r].first=dp[fi].first+1;//dp r-1 - lft[r] 的最小值和最小值的情况
                if(fi+2<r&&dp[fi+2].first==dp[fi].first) dp[r].second=3;
                else if(fi+1<r&&dp[fi+1].first==dp[fi].first){
                    dp[r].second=min(dp[fi+1].second+dp[fi].second,3);
                }
                else if(fi<r) dp[r].second=min(dp[fi].second,3);
                if(dp[r].second==2) ans++;
            }
        }    
        cout<<ans<<"\n";
    }
    else if(c<=12){
        ll x=a[2]-a[1];
        if(d/x<=1) cout<<0<<"\n";
        else cout<<max(0ll,n+1ll-(d/x)*2ll)<<"\n";
    }
    else if(c<=14){
        ll ans=0;
        for(int i=1;i<=n;i++){
            rgt[i]=lower_bound(a+1,a+1+n,a[i]+d+1)-a-1;
            lft[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
            cnt[lft[i]]++;
        }
        for(int i=1;i<=n;i++) if(rgt[i]) ans+=cnt[rgt[i]-1];
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    return 0; 
}