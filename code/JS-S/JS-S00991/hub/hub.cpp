#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,c,m;
vector<int>a[105];
int vis[105],v[105],e[105],sum;
void dfs1(int x,int fa,int k){
    e[x] = k;
    for (int i = 0;i < a[x].size();i++){
        if (a[x][i] != fa && vis[a[x][i]]){
            v[a[x][i]] = v[x]+1;
            dfs1(a[x][i],x,k);
        }
    }
}
void f(){
    memset(v,0,sizeof(v));
    memset(e,0,sizeof(e));
    vector<int>cnt;
    for (int i = 1;i <= n;i++){
        if (vis[i]){
            cnt.push_back(i);
            cout << i;
        }
    }
    int ans = 0;
    for (int i = 0;i < cnt.size();i++){
        if (!v[cnt[i]]){
            v[cnt[i]] = 1;
            ans += 1;
            dfs1(cnt[i],0,ans);
        }
    }
    if (ans > 2)return;
    int kk1 = 0,kk2 = 0,maxn1 = 0,maxn2 = 0;
    for (int i = 0;i < cnt.size();i++){
        if (e[cnt[i]] == 1 && v[cnt[i]] > maxn1){
            maxn1 = v[cnt[i]];
            kk1 = i;
        }else if(e[cnt[i]] == 2 && v[cnt[i]] > maxn2){
            maxn2 = v[cnt[i]];
            kk2 = i;
        }
    }
    memset(v,0,sizeof(v));
    v[kk1] = v[kk2] = 1;
    dfs1(kk1,0,0);
    dfs1(kk2,0,0);
    ans = 1;
    for (int i = 0;i < cnt.size();i++){
        ans = max(ans,v[cnt[i]]);
        //cout << v[cnt[i]] << ' ' <<cnt[i]<< "  ";
    }
    //cout << '\n';
    sum = min(ans,sum);
}
void dfs(int x,int sumk){
    if (x > n){
        if (sumk == m)
            f();
        return;
    }
    //cout << x;
    if (sumk > m)
        return;
    vis[x] = 1;
    dfs(x+1,sumk+1);
    vis[x] = 0;
    dfs(x+1,sumk);

}
void solve(){
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    sum = n;
    for (int i = 0;i <= n;i++)
        a[i].clear();
    for (int i = 1;i < n;i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(n,m);
    cout << sum << '\n';
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
