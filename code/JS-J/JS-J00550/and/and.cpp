#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+3;
const ll inf=1e9;
const int mod=998244353;
int n,m;
ll a[N],ans,ansmm,dp[2003][2003];
void solve(){
    cin>>n>>m;
    if(n<=2000){
        cin>>a[1];
        ansmm=a[1];
        dp[1][1]=a[1];
        pcr(i,2,n,1){
            cin>>a[i];
            dp[i][1]=a[i];
            ansmm&=a[i];
        }
        if(m==n){
            cout<<ansmm;
            return;
        }
        pcr(cnt,1,m,1){
            pcr(i,1,n,1){
                pcr(j,cnt-1,i-1,1){
                    dp[i][cnt]=max(dp[i][cnt],dp[j][cnt-1]&a[i]);
                }
            }
        }
        pcr(i,m,n,1) ans=max(ans,dp[i][m]);
        cout<<ans;
        return;
    }
    ll cnt[4]={0,0,0,0};
    pcr(i,1,n,1){
        cin>>a[i];
        if(a[i]==1) cnt[1]++;
        if(a[i]==2) cnt[2]++;
        if(a[i]==3) cnt[3]++;
    }
    sort(a+1,a+n+1);
    if(a[n]<=3){
        if(cnt[3]+cnt[2]>=m){
            cout<<2;
            return;
        }
        if(cnt[3]+cnt[1]>=m){
            cout<<1;
            return;
        }
        cout<<0;
        return;
    }
    ans=a[n];
    rcp(i,n,n-m+1,1) ans&=a[i];
    cout<<ans;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
