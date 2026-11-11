#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],cnt[300010],r,q[500010],b[500010];
bool vis[300010];
signed main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int r=1;r<=n;r++){
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        r=0;
        for(int i=r;i<=n;i++){
            if(vis[a[i]]==1){
                for(int j=b[a[i]]+1;j<=r;j++){
                    b[a[j]]=0;
                    vis[a[j]]=0;
                }
                r=b[a[i]];
            }
            else{
                vis[a[i]]=1;
                q[++r]=a[i];
            }
        }
        for(int i=1;i<=r;i++){
            cnt[q[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
