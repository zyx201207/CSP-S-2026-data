#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,k,c,t,ans=1e9;
vector<int> G[N],S;
bool vis[N],vis2[N];
struct node{
    int u,d;
};
int dis(int i,int j){
    queue<node> q;
    q.push({i,0});
    vis2[i]=1;
    while(!q.empty()){
        node f=q.front();
        q.pop();
        if (f.u==j)
            return f.d;
        for (auto v:G[f.u]){
            if (vis2[v])continue;
            vis2[v]=1;
            q.push({v,f.d+1});
        }
    }
}
int solve(){
    int r=0;
    for (int i=0;i<S.size();i++)
        for (int j=0;j<S.size();j++){
                if (i==j)continue;
                r=max(r,dis(S[i],S[j]));
    }
    return r;
}
void dfs(int cnt,int i,bool f,int L){
    if (cnt==k){
        ans=min(solve(),ans);
        return;
    }
    for (int j:G[i]){
        if (!f){
            if (L==2)
                dfs(cnt+1,j,1,L);
            else{
                dfs(cnt,j,0,L);
                S.push_back(j);
                dfs(cnt+1,j,1,L+1);
                S.pop_back();
            }
        }else{
            dfs(cnt,j,0,L);
            S.push_back(j);
            dfs(cnt+1,j,1,L+1);
            S.pop_back();
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++)
            vis[i]=0;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0,1,0,0);
        cout<<ans;
    }
    return 0;
}
