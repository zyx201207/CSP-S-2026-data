#include<bits/stdc++.h>
using namespace std;
int n,a[2020],m,dp[2020][2020],ans,mx,c1,c2,c3;
void solve(){
    if(c3>=m){
        cout<<3<<endl;
        return ;
    }
    if(c2+c3>=m){
        cout<<2<<endl;
        return ;
    }
    if(c1+c3>=m){
        cout<<1<<endl;
        return ;
    }
    cout<<0<<endl;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::ios::sync_with_stdio();
    std::cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            c1++;
        }
        if(a[i]==2){
            c2++;
        }
        if(a[i]==3){
            c3++;
        }
        mx=max(mx,a[i]);
    }
    if(mx<4){
        solve();
        return 0;
    }
    dp[0][0]=(1<<31)-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]&a[i+1]);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans<<endl;
    return 0;
}
