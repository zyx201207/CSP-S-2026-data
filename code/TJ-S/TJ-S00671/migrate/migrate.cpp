#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int x[N],nxt[N][23];
int ans,mn=1e18;
int n,d;
/*
inline void dfs(int pos,int step,int mn,int j){
    if (nxt[pos][0]==j){
        if (step+1==mn) ans++;
        return ;
    }
    for (int k=21;k>=0;k--){
        if (nxt[pos][k]<j){
            dfs(nxt[pos][k],step+(1ll<<k),mn,j);
            dfs(nxt[pos][k]-1,step+(1ll<<k),mn,j);
            break;
        }
    }
}
inline void dfs2(int pos,int step,int mn,int j){
    if (nxt[pos][0]==j){
        if (step+1==mn) ans++;
        return ;
    }
    for (int k=21;k>=0;k--){
        if (nxt[pos][k]<j){
            dfs2(nxt[pos][k],step+(1ll<<k),mn,j);
            dfs2(nxt[pos][k]-2,step+(1ll<<k),mn,j);
            break;
        }
    }
}
*/
inline void dfs(int s,int step,int t){
    if (s==t){
        if (step<mn){
            ans=1;
            mn=min(mn,step);
        }
        else if (step==mn) ans++;
    }
    for (int i=s+1;i<=t;i++){
        if (x[i]-x[s]<=d){
            dfs(i,step+1,t);
        }
    }
}
inline void solve(){
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>x[i];
    bool A=1;
    int diff=x[2]-x[1];
    for (int i=2;i<=n;i++){
        if (x[i]-x[i-1]!=diff){A=0;break;}
    }
    if (A){
        int p=d/diff;
        if (p<=1){
            cout<<0<<'\n';
            return ;
        }
        int kk=p*2;
        cout<<max(0ll,n-kk+1)<<'\n';
        return ;
    }
    if (n<=9){
        int cnt=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                mn=1e18,ans=0;
                dfs(i,0,j);
                if (ans==2) cnt++;
            }
        }
        cout<<cnt<<'\n';
        return ;
    }

    /*
    for (int i=1;i<=n;i++){
        for (int j=0;j<=21;j++) nxt[i][j]=0;
    }
    for (int i=1;i<=n;i++){
        int id=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
        nxt[i][0]=id;
    }
    for (int j=1;j<=21;j++){
        for (int i=1;i<=n;i++) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int now=i,mn=0;
            for (int k=21;k>=0;k--){
                if (nxt[now][k]<j) now=nxt[now][k],mn+=(1ll<<k);
            }
            mn++;
            now=nxt[now][0];
            ans=0;
            dfs(i,0,mn,j);
            dfs2(i,0,mn,j);
            if (ans==2){
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    */
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;cin>>c>>T;
    while (T--) solve();
    return 0;
}
