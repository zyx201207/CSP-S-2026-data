#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N = 1e6+10,inf = 1e8;
int n,_,c,d,f[N],x[N],in[N],dp[N];
vector<int> e[N];
void dfs(int u){
    for(auto v : e[u]){
        in[v]++;
        dfs(v);
    }
}
void tupo(int s){
    queue<int> q;
    q.push(s);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v : e[u]){
            dp[v]+=dp[u];
            if(dp[v]>inf)    dp[v]=inf;
            in[v]--;
            if(in[v]==0)    q.push(v);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> _;
    while(_--){
        cin >> n >> d;
        for(int i = 1;i <= n;i ++){
            cin >> x[i],f[i]=inf;
            e[i].clear();
        }
        int ans=0;
        f[1]=0;
        for(int i = 2;i <= n;i ++){
            int minn=inf;
            for(int j = i-1;j;j --){
                if(x[j]>=x[i]-d)    minn=min(minn,f[j]);
                else    break;
            }
            f[i]=minn+1;
            for(int j = i-1;j;j --){
                if(x[j]<x[i]-d) break;
                if(f[j]==minn){
                    e[j].pb(i);
                }
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = i;j <= n;j ++){
                in[j]=0;
                dp[j]=0;
            }
            dfs(i);
            dp[i]=1;
            tupo(i);
            for(int j = i;j <= n;j ++)  if(dp[j]==2)    ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}