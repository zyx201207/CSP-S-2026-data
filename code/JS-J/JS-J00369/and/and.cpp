#include<bits/stdc++.h>
using namespace std;
const int maxn=2002;
int n,m,ans=0;
int a[maxn],dp[maxn][maxn]; // dp[i][j]:now=i; have used j cnt
bool check(){
    for(int i=1;i<=n;i++){
        int temp=a[i]+1;
        while(a[i]%2==0){
            a[i]/=2;
        }
        if(a[i]!=1) return false;
    }
    return true;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(check()){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    for(int i=0;i<=n;i++) dp[i][0]=2147483647;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,m);j++){
            dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
