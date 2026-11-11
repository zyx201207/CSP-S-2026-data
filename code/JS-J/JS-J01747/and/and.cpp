#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],dp[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ans=-10;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(n==m){
        long long ans=-10;
        for(int i=1;i<=n;i++){
            ans=ans&&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        long long ans=-10;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    long long x=a[i] and a[j];
                    ans=max(ans,x);
                    cout<<x<<" ";
                }
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
