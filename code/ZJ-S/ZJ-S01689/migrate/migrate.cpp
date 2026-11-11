#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e6+10;
i64 a[N];
int lst[N],dp[N];
void solve(){
    int n;i64 d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    bool Sub1=1;
    for(int i=3;i<=n;i++)
        Sub1&=(a[i]-a[i-1]==a[2]-a[1]);
    if(Sub1){
        i64 k=d/(a[2]-a[1]);
        if(k<2)cout<<0<<'\n';
        else cout<<max(n-2*k+1,0ll)<<'\n';
        return;
    }
    for(int r=n,l=n;r;r--){
        while(l>1&&a[r]-a[l-1]<=d)l--;
        lst[r]=l;
    }
    i64 ans=0;
    for(int ed=1;ed<=n;ed++){
        dp[ed]=1;
        int l=ed,r=ed;
        while(l<=r){
            int x=lst[l],y=(l+1<=r?lst[l+1]:l),z=(l+2<=r?lst[l+2]:l);
            if(dp[l]>2||l==x)break;
            if(dp[l]==2)ans+=y-x;
            if(r>l&&dp[l]==1&&dp[l+1]==1)ans+=z-y;
            for(int i=x;i<=x+2&&i<l;i++){
                dp[i]=0;
                if(x<=i){dp[i]+=dp[l];
                if(y<=i){dp[i]+=dp[l+1];
                if(z<=i)dp[i]+=dp[l+2];}}
                if(dp[i]>2)dp[i]=3;
            }
            r=l-1,l=x;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Cid,T;cin>>Cid>>T;
    while(T--)solve();
    return 0;
}
//g++ -g migrate.cpp -o exe -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined