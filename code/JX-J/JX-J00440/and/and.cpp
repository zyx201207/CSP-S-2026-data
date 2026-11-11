#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,m,vis[N],mx=-1e5,ad;
void dfs(int x,int k){
    if(k==m+1){
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                ad=a[i];
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                ad=ad&a[i];
            }
        }
        mx=max(ad,mx);
        return;
    }
    for(int i=x+1;i<=n;i++){
        vis[i]=1;
        dfs(i,k+1);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(a[i],mx);
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        ad=a[1];
        for(int i=2;i<=n;i++){
            ad=ad&a[i];
        }
        cout<<ad;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ad=a[i]&a[j];
                mx=max(ad,mx);
            }
        }
        cout<<mx;
        return 0;
    }
    for(int i=1;i<=n-2;i++){
        memset(vis,0,sizeof vis);
        dfs(i,1);
    }
    cout<<mx;
    return 0;
}
