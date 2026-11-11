#include<bits/stdc++.h>
using namespace std;
int dp[23000][23000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i-1][0]=a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n){
        long long ans;
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        long long ans;
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        int pppp=0;
        while(ans!=0){
            ans>>1;
            pppp++;
        }
        long long mx=-1;
        long long xt=ans;
        for(int i=1;i<=n;i++){
            xt=ans^a[i]^((1<<pppp)-1);
            mx=max(xt,mx);
        }
        cout<<mx;
        return 0;
    }
    if(n>2000){
        int kpi=1;
        for(int i=0;i<20;i++){
            kpi*=2;
            if(n==kpi){
                //sort(a.begin(),a.end());
                cout<<a[n-1]&a[n-3];
                return 0;
            }
        }
        sort(a+1,a+n+1);
        cout<<a[n]&a[n-1];
        return 0;
    }
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max((dp[i-1][j-1] & a[i]),dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
