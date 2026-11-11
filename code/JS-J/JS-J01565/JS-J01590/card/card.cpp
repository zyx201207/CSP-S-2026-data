#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int vis[500005],cnt[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) f=0;
    }
    if(f){
        for(int i=1;i<=n;i++){
            vis[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<vis[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        int pos=0;
        memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                ++pos;
                vis[a[j]]=pos;
            }
            else{
                pos=vis[a[j]];
                for(int k=1;k<=m;k++){
                    if(vis[k]>pos) vis[k]=0;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j]) cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
