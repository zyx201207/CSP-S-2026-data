#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define mkp make_pair
using namespace std;
void solve(){
    int n,d;
    scanf("%lld%lld",&n,&d);
    vector<int>a(n+2,0);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int ans=0;
    vector<map<int,pii>>dp(n+2);
    //map<int,int> mp[hint]
    for(int i=1;i<=n;i++){
        dp[i][i]=mkp(0LL,1LL);//head,mi,cnt
        int len=dp[i].size();
        for(auto it=dp[i].begin();it!=dp[i].end();it++){
            int head=it->first,mi,cnt;
            mi=it->second.first;
            cnt=it->second.second;
            if(cnt==2)ans++;
            if(cnt>2)continue;
            for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++){
                if(dp[j][head]==mkp(0LL,0LL)){
                    dp[j][head]=mkp(mi+1,cnt);
                    continue;
                }
                if(dp[j][head].first>mi+1){
                    dp[j][head]=mkp(mi+1,cnt);
                }
                else if(dp[j][head].first==mi+1){
                    dp[j][head].second+=cnt;
                }
            }
        }
        dp[i].clear();
    }
    printf("%lld\n",ans);
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;
    scanf("%lld%lld",&c,&_);
    while(_--)solve();
    return 0;
}