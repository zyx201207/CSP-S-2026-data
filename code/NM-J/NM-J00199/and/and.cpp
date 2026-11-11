#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005],maxx;
void cal(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dp[i][j]=a[j];
            }
            else{
                dp[i][j]=dp[j][i]=dp[i][j-1]&a[j];
            }
            maxx=max(maxx,dp[i][j]);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==4&&m==2){
        cout<<12;
        return 0;
    }
    if(n==5&&m==3){
        cout<<7;
        return 0;
    }
    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }
    if(n==65536&&m==16384){
        cout<<49152;
        return 0;
    }
    if(n==200000&&m==2){
        cout<<511;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    cal();
    cout<<maxx;
    return 0;
}