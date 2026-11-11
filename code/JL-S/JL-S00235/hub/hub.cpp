#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int C,T,n,k;
vector<int> e[N];
bool vis[N];
int f[N];
inline int find(int x){
    if(f[x] == x)return x;
    return f[x] = find(f[x]);
}
inline int get_dis(int x,int fa,int dep){
    if(vis[x])return dep;
    int mn = INT_MAX;
    for(auto h : e[x]){
        if(h == fa)continue;
        mn = min(mn , get_dis(h , x , dep + 1));
    }
    return mn;
}
void brute_force(){
    int ans = 0x3f3f3f3f;
    for(int s = 0;s < (1 << n);s++){
        if(__builtin_popcount(s) != k)continue;
        for(int i = 1;i<=n;i++){
            if((s >> (i - 1)) & 1)vis[i] = 1;
            f[i] = i;
        }
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            for(auto h : e[i]){
                if(!(vis[i] && vis[h]))continue;
                int u = find(i),v = find(h);
                if(u != v);
                f[u] = v;
            }
        }
        for(int i = 1;i<=n;i++){
            if(vis[i] && (find(i) == i))cnt++;
        }
        if(cnt <= 2){
            int res = 0;
            for(int i = 1;i<=n;i++){
                res = max(res , get_dis(i , 0 , 0));
            }
            ans = min(ans , res);
        }
        for(int i = 1;i<=n;i++)vis[i] = 0;
    }
    cout<<ans<<"\n";
}
void solveA(){
    if(n == k){
        cout<<"0\n";
        return;
    }
    int m = n / 2;
    if(k >= m){
        cout<<"1\n";
        return;
    }
    for(int i = 1;i<=m;i++){
        int cov = i * 4 + k;
        if(k == 1){
            cov = i * 2 + 1;
        }
        if(cov >= m){
            cout<<i + 1<<"\n";
            return;
        }
    }
}
int main(){
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i = 1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(C == 13 || C == 14)solveA();
        else brute_force();
        for(int i = 1;i<=n;i++)e[i].clear();
    }
    return 0;
}
