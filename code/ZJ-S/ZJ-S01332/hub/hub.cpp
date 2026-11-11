#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e14;
const int N = 1e6 + 10;
int c,n,k,dep[N],vis[N],d[N],is[N],u[N],v[N];
vector<int> ve[N];
inline void dfs(int er,int fa){
    dep[er] = dep[fa] + 1;
    int len = ve[er].size();
    for (int i = 0; i < len;i++){
        int go = ve[er].size();
        if(go==fa)
            continue;
        dfs(go, er);
    }
}
inline int bfs(int x){
    for (int i = 1; i <= n;i++)d[i]=inf;
    queue<int> q;
    q.push(x);
    d[x] = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        int len = ve[f].size();
        for (int i = 0; i < len;i++){
            int go = ve[f][i];
            if(is[go]){
                return d[f] + 1;
            }
            if(d[go]>d[f]+1){
                d[go] = d[f] + 1;
                q.push(go);
            }
        }
    }
    return inf;
}
inline bool check(int msk){
    int cnt = 0;
    for(int i=1;i<n;i++){
        int s1=u[i]-1,s2=v[i]-1;
        if((msk&(1<<s1))&&(msk&(1<<s2))){
            cnt++;
        }
    }
    if(cnt>=k-2)
        return 1;
    return 0;
}
inline void solve(){
    cin>>n>>k;
    for (int i = 1; i <= n;i++)
        ve[i].clear();
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        u[i] = x, v[i] = y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    if(c<=3){
        int mn = inf;
        for (int i = 0; i < (1 << n);i++){
            for (int j = 1; j <= n;j++)
                is[j] = 0;
            int cnt = 0;
            for (int j = 0; j < n;j++)
                if(i&(1<<j)){
                    cnt++;
                    is[j + 1] = 1;
                }
            if(cnt==k&&check(i)){
                int mx = 0;
                for (int j = 0; j < n;j++){
                    if(!(i&(1<<j))){
                        mx=max(mx,bfs(j+1));
                    }
                }
                mn = min(mn, mx);
            }
        }
        cout << mn << '\n';
    }
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
/*

*/