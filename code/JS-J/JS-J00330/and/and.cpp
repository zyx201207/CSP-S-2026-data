#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0,a[200001];
int dp(int v,int j,int k,int ans){
    if(k==0)return v&a[j];
    for(int i=j+1;i<=n;i++){
        ans=max(dp(a[j],i,k-1,ans),ans);
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-m+1;i++){
        maxn=max(dp(a[i],i,m-1,0),maxn);
    }
    cout<<maxn;
    return 0;
}
