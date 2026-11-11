#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],dp[2005][2005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }cout<<a[m];
    return 0;
}
