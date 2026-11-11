#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x=0;char c=getchar();
    while (!isdigit(c))c=getchar();
    while (isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

ll a[2000005],L[2000005],R[2000005];
ll dp[2000005],dp2[2000005],cnt[2000005];
ll co1[2000005],co2[2000005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    ll c,t;
    cin >> c >> t;
    while (t--){
        ll n,d;
        cin >> n >> d;
        for (ll i=1;i<=n;i++){
            cin >> a[i];
        }
        for (ll i=0;i<=n+1;i++)L[i]=R[i]=dp[i]=cnt[i]=0;
        ll ps=0;
        for (ll i=1;i<=n;i++){
            while (ps+1<=n&&a[ps+1]-a[i]<=d)ps++;
            R[i]=ps;
        }
        ps=n+1;
        for (ll i=n;i>=1;i--){
            while (ps-1>=1&&a[i]-a[ps-1]<=d)ps--;
            L[i]=ps;
        }
        ll ans=0;
        ps=n;
        for (ll i=n;i>=1;i--){
            /*ll c=0;
            for (ll j=i+1;j<=R[i];j++){
                c+=(L[j]==i);
            }*/
            while (ps>R[i]){
                cnt[L[ps]]--;ps--;
            }
            if (i+1<=ps)cnt[L[i+1]]++;
            dp[i]=cnt[i];
            co2[i]=cnt[i-1];
            if (L[R[i]]==i){
                dp[i]+=dp[R[i]];
            }
            //cout<<"??"<< i<<":"<< dp[i]<<"\n";
        }
        for (ll i=0;i<=n+1;i++)cnt[i]=0;
        ps=1;
        for (ll i=1;i<=n;i++){
            /*ll c=0;
            for (ll j=L[i];j<=i-1;j++){
                c+=(R[j]==i);
            }*/
            while (ps<L[i]){
                cnt[R[ps]]--;
                ps++;
            }
            if (i-1>=ps)cnt[R[i-1]]++;
            dp2[i]=cnt[i];
            co1[i]=cnt[i+1];
            if (R[L[i]]==i){
                dp2[i]+=dp2[L[i]];
            }
        }
        for (ll i=2;i<n;i++){
            /*ll c=0;
            for (ll j=L[i];j<=i-1;j++){
                c+=(R[j]==i+1);
            }*/
            if (L[R[i+1]]==i)ans+=dp[R[i+1]]*co1[i];
            /*c=0;
            for (ll j=i+2;j<=R[i+1];j++){
                c+=(L[j]==i);
            }*/
            if (R[L[i]]==i+1)ans+=dp2[L[i]]*co2[i+1];
            if (R[L[i]]==i+1&&L[R[i+1]]==i)ans+=dp2[L[i]]*dp[R[i]];
        }
        for (ll i=2;i<n;i++){
            //ll c1=0,c2=0;
            //for (ll j=L[i];j<=i-1;j++)c1+=(R[j]==i+1);
            //for (ll j=i+2;j<=R[i+1];j++)c2+=(L[j]==i);
            //assert(c1==)
            ans+=co1[i]*co2[i+1];
        }
        cout<< ans<<"\n";
    }
    return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
