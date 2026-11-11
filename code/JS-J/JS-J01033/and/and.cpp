#include <bits/stdc++.h>
using namespace std;

vector<long long> ap;
long long dp[200005];
long long dpold[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    ap.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>ap[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dpold[j]=dp[j];
            if(j==0) {dp[j]=0;continue;}
            if(j==1) {dp[j]=max(dp[j],ap[i]);continue;}
            if(j<=i){
                dp[j]=max(dp[j],dpold[j-1]&ap[i]);
            }
            else{dp[j]=0;}
        }
        //ans=max(ans,dp[m]);
    }
    cout<<dp[m];
    return 0;
}




