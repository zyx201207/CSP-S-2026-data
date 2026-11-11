#include<bits/stdc++.h>
using namespace std;
#define int long long
ifstream fin("card.in");
ofstream fout("card.out");
#define cin fin
#define cout fout
int n,m;
int a[5005];
int r[5005];
int d[5005];
int res[5005];
int bt[3005];
int dp[5005][3005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) r[i]=n+1;
    for(int i=1;i<=n;++i){
        r[a[i]]=i;
        d[a[i]]++;
    }
    for(int i=n;i>=1;--i){
        dp[i][a[i]]++;
        for(int j=1;j<=m;++j)
            dp[i][j]+=dp[r[a[i]]+1][j];
        res[a[i]]++;
        for(int j=1;j<=m;++j) res[j]+=dp[r[a[i]]+1][j];
    }
    for(int i=1;i<=m;++i) cout<<res[i]+d[i]<<" ";
    return 0;
}
