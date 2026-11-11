#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,a[5005],minn[5005],vis[5005];
void dfs(int i,int dep){
    if(minn[i]>dep){
        minn[i]=dep;
        vis[i]=0;
    }
    if(minn[i]==dep){
        ++vis[i];
    }
    for(int j=i+1;j<n && a[j]<=a[i]+d;j++){
        dfs(j,dep+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans=0;
        memset(a,0,sizeof(a));
        cin >> n >> d;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            memset(minn,127,sizeof(minn));
            memset(vis,0,sizeof(vis));
            dfs(i,0);
            for(int j=i;j<n;j++){
                if(vis[j]==2){
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}
