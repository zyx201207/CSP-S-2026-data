#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int a[N],n,c,t,d,step,ans,cnt;
int dp[N];

void dfs(int l,int dep,int r){
    if(l == r){
        step = min(step,dep);
        return ;
    }
    for(int i=l+1;i<=r;i++){
        if(a[i] - a[l] <= d)
            dfs(i,dep+1,r);
    }
}

void dfs2(int l,int dep,int r,int dx){
    //cout<<l<<" "<<dep<<" "<<r<<endl;
    if(ans > 2 || dep > dx) return ;
    if(l == r){
        if(dep == dx) ans ++;
        return ;
    }
    for(int i=l+1;i<=r;i++){
        if(a[i] - a[l] <= d)
            dfs2(i,dep+1,r,dx);
    }
}


signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                step = INT_MAX;
                dfs(i,0,j);
                if(step == INT_MAX) continue;
                ans = 0;
                dfs2(i,0,j,step);
                //if(i == 1 && j == 4) cout<<ans<<endl;
                if(ans == 2) cnt ++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
