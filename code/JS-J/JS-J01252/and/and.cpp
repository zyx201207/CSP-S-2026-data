#include<bits/stdc++.h>
using namespace std;
long long a[1005],dp[1005];
int n,m;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1ll,a+n+1ll,cmp);
    for(int i=1;i<=n;i++){
        dp[1]=a[1];
    }
    for(int i=1;i<=n;i++){
        for(int j=min(i,m);j>=2;j--){
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}