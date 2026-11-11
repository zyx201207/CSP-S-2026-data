#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int inf=0x3f3f3f3f;
int f[N][N], t[N][N], a[N][N], w[500005];
vector<pair<int, int> > g[N];
vector<int> h[N];
bool vis[N];
int dfs(int u, int v, int now, int ans){//now means current line
    for(auto cur: g[u]){
        int to=cur.first, i=cur.second;
        //cout<<to<<' ';
        if(vis[to]) continue;
        vis[to]=1;
        if(to==v){
            if(i==now) return t[i][to];
            else return t[i][to]+(t[now][u]+t[i][u]);
        }
        if(i==now) ans+=t[i][to]+dfs(to, v, now, ans);
        else ans+=t[i][to]+(t[now][u]+t[i][u])+dfs(to, v, i, ans);
    }
    //cout<<ans<<' ';
    return ans;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, d, q, cnt=0, time;
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++) cin>>w[i];
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        for(int j=1; j<=k; j++){
            cin>>a[i][j]>>t[i][a[i][j]]; h[a[i][j]].push_back(i);
            time=t[i][a[i][j]];
            for(int x=1; x<j; x++){
                g[a[x][j]].push_back({a[i][j], i});
                g[a[i][j]].push_back({a[x][j], i});
            }
        }
    }
    if(n==2){
        while(q--){
            int s, e, flag=0;
            cin>>s>>e;
            for(int v: h[s]){
                for(int u: h[e]){
                    if(v==u) {flag=v;break;}
                }
            }
            if(flag){
                cout<<w[s]+w[e]+t[flag][s]+t[flag][e]<<'\n';
            }
            else{
                int ans=0, sum=inf;
                ans+=w[s]+w[e]+t[h[s][0]][s]+t[h[e][0]][e];
                for(int i=1; i<=m; i++){
                    if(h[i].size()==2){
                        sum=min(sum, t[h[s][0]][i]+t[h[e][0]][i]);
                        //cout<<t[h[e][0]][i]<<' ';
                    }
                }
                cout<<ans+sum<<'\n';
            }
        }
        return 0;
    }

    while(q--){
        int s, e;
        cin>>s>>e;
        int ans=inf, line;
        for(int v:h[s]){
            if(ans>dfs(s, e, v, 0)){
                ans=min(ans, dfs(s, e, v, 0));
                line=v;
            }
        }
        ans+=w[s]+w[e]+t[line][s];
        cout<<ans<<'\n';
    }

    return 0;
}
