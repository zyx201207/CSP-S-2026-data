#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,res,idx;
int a[N],dp[2][N][2];
bool flag=1,flag1=1;
inline void Dfs(int u,int sum,int num) {
    if(m==num) {
        res=max(res,sum);
        return ;    
    }
    if(u==n+1) {
        if(num==m)  res=max(res,sum);
        return ;
    }
    if(n-u+1+num<m) return ;
    Dfs(u+1,sum,num);
    Dfs(u+1,(sum==-1 ? a[u]:(sum&a[u])),num+1);
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=i-1)   flag=false;
        if(i==1)    idx=a[i];
        else    idx&=a[i];
        if(__builtin_popcount(a[i]+1)!=1)   flag1=0;
    }
    if(n!=pow(2,m)) flag=false;
    if(flag1) {
        sort(a+1,a+1+n);
        cout<<a[m]<<"\n";
        return 0;
    }
    if(n==m) {
        cout<<idx<<"\n";
        return 0;
    }
    if(m==2) {
        for(int i=1;i<=n;i++)   for(int j=i+1;j<=n;j++) res=max(res,a[i]&a[j]);
        cout<<res<<"\n";
        return 0;
    }
    if(!flag) {
        Dfs(1,-1,0);
        cout<<res<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++) {
        dp[i&1][1][1]=a[i];
        dp[i&1][1][0]=max(dp[(i-1)&1][1][0],dp[(i-1)&1][1][1]);
        for(int j=2;j<=m;j++) {
            dp[i&1][j][1]=max((dp[(i-1)&1][j-1][0]&a[i]),(dp[(i-1)&1][j-1][1]&a[i]));
            dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
            //cout<<i<<" "<<j<<" "<<dp[i&1][j][0]<<" "<<dp[i&1][j][1]<<"\n";
        }
        res=max({res,dp[i&1][m][0],dp[i&1][m][1]});
    }
    cout<<res<<"\n";
    return 0;
}