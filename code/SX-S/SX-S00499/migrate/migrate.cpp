#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005];
int vis[2000005],mn;
void dfs(int dep,int step,int r){
    if(dep>r) return;
    if(dep==r){
        vis[step]++;
        mn=min(mn,step);
    }
    for(int i=1;x[dep+i]-x[dep]<=d&&i<=n;i++){
        dfs(dep+i,step+1,r);
    }
}
bool isnega(int l,int r){
    memset(vis,0,sizeof(vis));
    mn=LLONG_MAX;
    dfs(l,0,r);
    return vis[mn]==2;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int ans=0;
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                if(isnega(l,r)) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
unsigned long long rp=-1;