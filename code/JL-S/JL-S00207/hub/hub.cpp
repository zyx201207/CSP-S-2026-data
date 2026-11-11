#include<bits/stdc++.h>
using namespace std;
const int N=15;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x*f;
}
int n,k;
vector<int> G[N];
int fa[N];
bool f[N];
void dfs(int u){
    for(auto v:G[u]){
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs(v);
    }
}
int mn;
void dfs2(int u,int Fa,int d){
    if(f[u]) mn=min(d,mn);
    for(auto v:G[u]){
        if(v==Fa) continue;
        dfs2(v,u,d+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),T=read();
    while(T--){
        n=read(),k=read();
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        fa[0]=-1;
        dfs(0);
        int ans=100;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=k) continue;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    f[j]=1;
                }
                else f[j]=0;
            }
            int cnt=k;
            for(int j=0;j<n;j++){
                if(f[j]){
                    if(j && f[fa[j]]) cnt--;
                }
            }
            if(cnt>2) continue;
            int mx=0;
            for(int j=0;j<n;j++){
                if(!f[j]){
                    mn=100;
                    dfs2(j,-1,0);
                    mx=max(mx,mn);
                }
            }
            ans=min(ans,mx);
        }
        printf("%d\n",ans);
    }
    return 0;
}
