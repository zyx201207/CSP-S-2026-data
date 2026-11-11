#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int mx=-1e9;
int dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        mx=max(mx,a[i]);
    }
    if(m==1)cout<<mx;
    if(m==2){
        mx=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)mx=max(mx,a[i]&a[j]);
        }
        cout<<mx;
    }
    if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++)mx=mx&a[i];
        cout<<mx;
    }
    for(int i=0;i<=m;i++)dp[i]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=min(i,m);j>=0;j--){
            if(j==0)dp[j]=a[i+1];
            if(j!=i)dp[j]=max(dp[j-1]&a[i],dp[j]);
            else dp[j]=dp[j-1]&a[i];
        }
    }
    cout<<dp[m];
    return 0;
}
