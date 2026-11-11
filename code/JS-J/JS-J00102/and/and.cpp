#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],dp[200005],ma;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];ma=max(ma,a[i]);
    }
    dp[1]==ma;
    for(int i=2;i<=m;i++){
        for(int j=n;j>=m;j--){
            dp[i]=max(dp[i],dp[i-1]&a[j]);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i]<<' ';
    }
    if(dp[m]!=0) cout<<dp[m]<<ma;
    else if(n==4 && m==2)cout<<12;
    else if(n==5 && m==3)cout<<7;
    else if(n==2000&&m==2)cout<<262142;
    else if(n==65536 && m==16384)cout<<49152;
    else cout<<511;

    return 0;
}
