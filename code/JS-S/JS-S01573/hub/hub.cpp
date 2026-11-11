#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<vector<int>>tree;
void dfs(int x,bitset<20> &vis,int &sta){
    // if (vis[x])return ;
    for (auto y:tree[x]){
        if (vis[y]) continue;
        if (sta&(1<<(y-1))){
            vis[y]=1;
            dfs(y,vis,sta);
        }
    }
    // if (sta==518)cout<<x<<" ";
}
void gts(int x,vector<int> & ans,bitset<20> vis){
    for (auto y:tree[x]){
        if (vis[y]) continue;
        vis[y]=1;
        ans[y]=min(ans[y],ans[x]+1);
        gts(y,ans,vis);
    }
}
void solve1(){
    int anss=100;
    for (int i=0;i<(1<<n);i++){
        bitset<20>vis;
        if (__builtin_popcount(i)!=k) continue;
        int tim=0;
        vector<int> ans(20);
        // cout<<"\n\n\n";
        for (int j=1;j<=n;j++){
            ans[j]=100;
            if (!vis[j]&&(i&(1<<j-1))) {
                dfs(j,vis,i);tim++;
                // if (i==518)cout<<j<<" ";
            }
        }
        if (tim>2) continue;
        for (int j=1;j<=n;j++){
            vis&=0;
            vis[j]=1;
            if (i&(1<<j-1)){
                ans[j]=0;
                gts(j,ans,vis);
            }
        }
        int tmp=0;
        for (int j=1;j<=n;j++){
            tmp=max(ans[j],tmp);
        }
        // cout<<tmp<<" ";
        // if (tmp==1) {bitset<10> zz=i;
        // cout<<"   a"<<zz<<"b   "  <<i<<"c";}
        anss=min(anss,tmp);
    }

    cout<<anss<<"\n";
    // cout<<"********************\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    for (int i=1;i<=t;i++){
        tree.resize(0);
        cin>>n>>k;
        if (k==n){
            cout<<0<<"\n";
            continue;
        }
        tree.resize(n+5);
        for (int j=1;j<n;j++){
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if (c<=3){
            solve1();
        }
        else {
            cout<<114514<<"\n";
        }
    }
        // cout<<(518&(1<<9));
    return 0;
}