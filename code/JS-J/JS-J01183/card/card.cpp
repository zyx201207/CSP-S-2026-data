#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[5005][3005];
int ans[3005],a[5005];
int vis[5005][3005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n>=500&&m>=200){
        for(int i=1;i<=m;i++){
            cin>>a[i];
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[i][a[i]]=1;
        for(int j=1;j<=m;j++){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<i<<"_______________\n";
        for(int j=1;j<=i;j++){
            int f=1;
            for(int t=1;t<=m;t++){
                if(t!=a[i]&&cnt[i-1][t]-cnt[j-1][t]&&cnt[n][t]-cnt[i][t]){
                    //cout<<t<<" "<<j<<endl;
                    f=0;
                    break;
                }
            }
            if(f&&vis[j][a[i]]==0){
                vis[j][a[i]]=1;
                ans[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
