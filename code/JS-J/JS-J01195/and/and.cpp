#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],dp[N],mx[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    for(int i=1;i<=n;++i){
        dp[1]=mx[i-1];
        for(int j=min(i,m);j>=2;j--){
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    dp[1]=mx[n];
    cout<<dp[m];
    //for(int i=1;i<=n;++i)
    //    cout<<mx[i]<<'\n';
    return 0;
}
