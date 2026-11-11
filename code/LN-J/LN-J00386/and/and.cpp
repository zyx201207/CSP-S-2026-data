#include<bits/stdc++.h>

using namespace std;
int n,m;
long long a[200005];
long long f[200005];
int vis[200005];
long long ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
   cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]&a[i];
    }
    if(m==1){
        long long mx=-1e9;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    else if(m==n){
        cout<<f[n];
        return 0;
    }
   long long mx1=-1e9;
   long long mx1w; 
   for(int i=1;i<=n;i++){
       mx1=max(mx1,a[i]);
       if(a[i]>mx1){
           mx1w=i;
       }
   }
   ans=mx1;
    vis[mx1w]=1;
    for(int i=2;i<=m;i++){
        long long mx=-1e9;
        long long mxw;
        for(int j=1;j<=n;j++){
            if(vis[j]==1)continue;
            mx=max(mx,(ans&a[j]));
            if(mx<(ans&a[j])){
                mxw=j;
            }
        }
        ans=mx;
        vis[mxw]=1;
    }
    cout<<ans;
    return 0;
}