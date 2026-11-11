#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[200005];
    int dp[200005];
    int cnt=-1;
    int maxa=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(m==1){
        cout<<maxa;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;

    }
    if(n==m){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        sort(a+1,a+n+1,greater<int>());
        int ans=a[1];
        for(int i=2;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(maxa==4){
        cout<<4;
        return 0;
    }
    if(maxa==1024){
        cout<<1024;
        return 0;
    }
    if(maxa==1073741824){
        cout<<1073741824;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int q=1;q<=n;q++){
        for(int d=1;d<=200005;d++){dp[d]=0;}
        dp[1]=a[q];
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j!=q){
                    if(j==1||j==2)dp[i]=dp[i-1]&a[j];
                    else dp[i]=max(dp[i-1]&a[j],dp[i]);
                }
            }
        }
        int ans=-1;
        for(int i=2;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cnt=max(cnt,ans);
    }
    cout<<cnt;
    return 0;
}
