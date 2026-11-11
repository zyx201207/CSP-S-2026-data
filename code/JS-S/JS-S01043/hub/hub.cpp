#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        long long n,k;
        long long a[1005][1005]={};
        long long vis[1005];
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            long long u,v;
            cin>>u>>v;
            a[u][v]=1;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                vis[i]=i;
            }
            for(int j=1;j<=n;j++){
                if(a[i][j]==1){
                    vis[j]=vis[i];
                }
            }
        }
        long long cnt[1005]={};
        for(int i=1;i<=n;i++){
            cnt[vis[i]]++;
        }
        long long ans;
        for(int i=1;i<=n;i++){
            if(cnt[i]>0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
