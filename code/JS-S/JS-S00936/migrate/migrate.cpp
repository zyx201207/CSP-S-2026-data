#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=2e6+5;

int tc;

int n; ll d;
ll a[N];
ll dp[N],cnt[N];

void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(tc==11 || tc==12){
        ll x=a[2]-a[1];
        if(d/x<=1) puts("0");
        else printf("%lld\n",max(0ll,n-(d/x*2-1)));
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        dp[i]=1; cnt[i]=1;
        for(int j=i+1;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[j]-a[k]<=d){
                    if(dp[k]+1<dp[j]){
                        dp[j]=dp[k]+1;
                        cnt[j]=cnt[k];
                    }else if(dp[k]+1==dp[j]){
                        cnt[j]+=cnt[k];
                    }
                }
            }
            if(cnt[j]==2) ans++;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%d%d",&tc,&t);
    while(t--) solve();
    return 0;
}
