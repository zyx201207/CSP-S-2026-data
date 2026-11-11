#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[202020];
int b[202020][40];
int vis[202020];
int ba[40];
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            if((a[i]>>(j-1))&1){
                b[i][j]=1;
            }
            else{
                b[i][j]=0;
            }
        }
    }
    for(int mask=30;mask>=1;mask--){
        int la=0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                if(b[i][mask]){
                    la++;
                }
            }
        }
        if(la>=m){
            for(int i=1;i<=n;i++){
                if(!b[i][mask]){
                    vis[i]=0;
                }
            }
            ba[mask]=1;
        }
    }
    for(int i=1;i<=30;i++){
        if(ba[i]){
            ans+=(1<<(i-1));
        }
    }
    cout<<ans;
}