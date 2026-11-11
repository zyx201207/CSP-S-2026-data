#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1);
    vector<vector<long long> > dp(n+1,vector<long long>(m+1,0));
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a.begin()+1,a.end(),greater<long long>());
    for(int i=1;i<=n;i++) dp[i][1]=maxn;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i-1][j-1]<<" "<<a[i]<<endl;
            cout<<((dp[i-1][j-1])&(a[i]))<<endl;
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][m]);
    cout<<ans<<endl;
}
