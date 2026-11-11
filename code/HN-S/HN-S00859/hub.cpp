#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> nbr[N];
int c,T,n,k;
bool vis[N];
int col[N],mxdep[N];
int bu(int x){
    int res=0;
    while(x){res+=x&1;x>>=1;}
    return res;
}
void dfs(int cur,int fa,int de){
    col[cur]=min(col[cur],de);
    for(int nxt:nbr[cur]){
        if(nxt==fa)continue;
        dfs(nxt,cur,de+1);
    }
    return ;
}
void dff(int cur,int fa,int x){
    vis[cur]=1;
    for(int nxt:nbr[cur]){
        if(nxt==fa)continue;
        if(((x>>nxt-1)&1)==1)dff(nxt,cur,x);
    }
    return ;
}
void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)nbr[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        nbr[u].push_back(v);
        nbr[v].push_back(u);
    }
    if(n<=10){
        int ans=100000,cnt=0;
        for(int i=1;i<(1<<n);i++){
            cnt=0;
            if(bu(i)!=k)continue;
            for(int j=1;j<=n;j++)col[j]=100000000,vis[j]=0;
            for(int j=1;j<=n;j++){
                if(((i>>j-1)&1)==1){
                    if(!vis[j]){
                        cnt++;
                        dff(j,0,i);
                    }
                    dfs(j,0,0);
                }
            }
            // cerr<<i<<' '<<cnt<<'\n';
            if(cnt<=2){
                // cerr<<"aba"<<i<<'\n';
                int now=0;
                for(int j=1;j<=n;j++)now=max(now,col[j]);
                ans=min(ans,now);
            }
        }
        cout << ans << '\n';
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> T;
    while(T--)solve();
    return 0;
}