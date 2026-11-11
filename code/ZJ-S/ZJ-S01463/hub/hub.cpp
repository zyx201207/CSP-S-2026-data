#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>vec[15];
bool vis[15];
bool lok[15];
void dfs(int u){
    lok[u]=true;
    for (int v:vec[u]){
        if (lok[v]==false&&vis[v]==true)dfs(v);
    }
}
bool check(){
    int cnt=0;
    memset(lok,false,sizeof(lok));
    for (int i=1;i<=n;i++){
        if (vis[i]==true&&lok[i]==false){
            cnt++;
            dfs(i);
        }
    }
    if (cnt<=2)return true;
    return false;
}
int dep[15];
int res;
void dfs2(int fa,int u){
    dep[u]=dep[fa]+1;
    if (vis[u]==true){
        res=min(res,dep[u]-1);
        return ;
    }
    for (int v:vec[u]){
        if (v==fa)continue;
        dfs2(u,v);
    }
}
int calc(){
    int ans=0;
    for (int i=1;i<=n;i++){
        res=1e9;
        dfs2(0,i);
        ans=max(ans,res);
    }
    return ans;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T,u,v;
    scanf("%d%d",&c,&T);
    while (T--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++)vec[i].clear();
        for (int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        int ans=1e9;
        for (int i=0;i<(1<<n);i++){
            int i1=i,cnt=0,t=0;
            memset(vis,false,sizeof(vis));
            while (i1){
                cnt++;
                if (i1%2==1)vis[cnt]=true,t++;
                else vis[cnt]=false;
                i1/=2;
            }
            if (t!=k)continue;
            if (check()==false)continue;
            ans=min(ans,calc());
        }
        printf("%d\n",ans);
    }
    return 0;
}