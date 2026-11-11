#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],dp[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++)dp[i]=-1;
    for(int i=1;i<=n;i++){
        for(int j=min(m,i);j>=1;j--){
            if(dp[j-1]==-1)dp[j]=max(a[i],dp[j]);
            else dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
