#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int x[1000005],r;
int vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2 && n>5000){
        for(int i=1;i<=n;i++){
            int j;
            if(n-i>=2){
                j=n-2;
                ans[a[n]]++;
                if(a[j]!=a[n]){
                    ans[a[j]]++;
                }
            }
            else if(n-i==1){
                ans[a[n]]++;
                if(a[n-1]!=a[n]){
                    ans[n-1]++;
                }
            }
            else{
                ans[a[n]]++;
            }
        }
        cout<<ans[1]<<' '<<ans[2];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        r=1;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                r++;
                x[r]=a[j];
                vis[a[j]]=r;
            }
            else{
                for(int l=vis[a[j]]+1;l<=r;l++){
                    vis[x[l]]=0;
                    x[l]=0;
                }
                r=vis[a[j]];
            }
        }
        for(int j=2;j<=r;j++){
            ans[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
