#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200086],dp[200086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=a[i];
    }
    if(m==0||m==1){
        cout<<0;
        return 0;
    }
    for(int i=2;i<=m;i++){

        for(int j=n;j>1;j--){
            int ans=0;
            for(int k=n;k>1;k--){
                if(k!=j){
                    ans=max(ans,dp[k]&a[j]);
                }

            }
            dp[j]=ans;
        }
    }
    cout<<dp[n];
    return 0;
}
