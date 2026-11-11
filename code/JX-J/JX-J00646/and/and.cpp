#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int INF=(1<<30)-1;
int n,m;
int a[N],dp[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    dp[0]=INF;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=min(i,m);j>=1;j--)
            dp[j]=max(dp[j],dp[j-1]&a[i]);
    cout<<dp[m];
    return 0;
}
