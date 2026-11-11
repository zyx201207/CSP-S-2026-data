#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define SZ(a) (int)a.size()-1
#define fi first
#define se second
#define mkp make_pair
using ll=long long;
using namespace std;

namespace MyCode{
    const int N=2e6+10;
    int n;
    ll a[N], len;
    // int w[N], c[N], tl[N];
    int dp[3][N];
    bool vis[N];
    vector<int>g[N];
    void dfs(int x) {
        dp[0][x]=dp[1][x]=dp[2][x]=0;
        rep(i, 0, SZ(g[x])) {
            int y=g[x][i];
            dfs(y);
            if(i==0) dp[0][x]=dp[0][y]+1, dp[1][x]+=dp[1][y];
            else dp[0][x]++;
            if(i==0&&g[x][SZ(g[x])]==x-1) dp[2][x]+=dp[2][y]+1;
            else dp[2][x]++;
            // dp[2][x]+=
            if(i==1) dp[1][x]+=dp[0][y];
        }
    }
    void Main(){
        cin>>n>>len;
        rep(i, 1, n) cin>>a[i], g[i].clear(), vis[i]=0;
        int l=0, r=1;
        while(++l<=n) {
            r=max(r, l);
            while(r<n&&a[r+1]-a[l]<=len) r++;
            if(r!=l) g[r].push_back(l);
            if(r!=l) vis[l]=1;
            // if(l<r) cout<<"EDGE: "<<l<<' '<<r<<'\n';
            // tl[l]=r;
        }
        rep(i, 1, n) if(!vis[i]) dfs(i);
        rop(x, n, 1) if(g[x].size()>0&&(g[x][SZ(g[x])]!=x-1)) dp[2][x]+=dp[2][g[x][0]]-1;
        // cout<<dp[2][3]<<'\n';
        l=1, r=0;
        ll ans=0;
        while(++r<=n) {
            while(l<r&&a[l]+len<a[r]) l++;
            // ll tmp=ans;
            if(l<r) ans+=dp[1][l];
            if(l<r-1) ans+=dp[2][l+1];
            // cout<<ans-tmp<<'\n';
        }
        cout<<ans<<'\n';
        // rep(t, 1, n) {
        //     c[t]=1;
        //     rop(j, t-1, 1) {
        //         w[j]=c[j]=0;
        //         int to=min(t, tl[j]);
        //         if(to>j) w[j]=w[to]+1;
        //         if(to>j+1&&w[to]==w[to-1]) c[j]=(c[to]>1||c[to-1]>1)?3:2;
        //         else if(to>j) c[j]=c[to];
        //     }
        //     // rep(j, 1, n) cout<<w[j]<<' '; cout<<'\n';
        //     // rep(j, 1, n) cout<<c[j]<<' '; cout<<'\n';
        //     // cout<<"------------------------------\n";
        //     rep(j, 1, n) if(c[j]==2) cout<<j<<' '<<t<<'\n';
        // }
    }
}
/*
0 1
10 333333333333333327
-1000000000000000000 
-666666666666666673 
-333333333333333346 
-111111111111111128 
111111111111111090 
222222222222222199 
333333333333333308
444444444444444417
666666666666666635
999999999999999962


0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/
int main(){
//  freopen("migrate.in", "r", stdin);
//  freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T=1, id;
    cin>>id>>T;
    // MyCode::init();
    while(T--) MyCode::Main();
    return 0;
}