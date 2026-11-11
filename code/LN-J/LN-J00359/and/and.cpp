#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],dp[2010][2010],s=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout <<a[n];
        return 0;
    }
    else if(m==n){
        for(int i=1;i<=n;i++) s&=a[i];
        cout <<s;
        return 0;
    }
    for(int i=1;i<=n;i++) dp[i][1]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i][j-1]&a[i]);
        }
    }
    cout <<dp[n][m];
    return 0;
}
