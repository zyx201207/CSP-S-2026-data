#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int vis[3000005],vs[3000005],a[3000005],cnt[3000005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int ii=0;ii<n;ii++){
        int now=1;
        memset(vis,0,sizeof vis);
        memset(vs,0,sizeof vs);
        for(int i=1+ii;i<=n;i++){
            if(vis[a[i]]&&vis[a[i]]<=now){
                now=vis[a[i]];
                vis[a[i]]=now;
                vs[now]=a[i];
            }
            else{
                vis[a[i]]=now;
                vs[now]=a[i];
            }
            now++;
        }
        now--;
        for(int i=1;i<=m;i++){
            if(vis[i]&&vs[vis[i]]==i&&vis[i]<=now){
                cnt[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
