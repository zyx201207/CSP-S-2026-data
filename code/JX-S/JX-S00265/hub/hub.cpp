#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
void outt(ll x){
    if(x<0){
        x=-x;
    }
    char ch=x%10+'0';
    if(x>=10)outt(x/10);
    putchar(ch);
}
const int N=1e6+5;
ll c,t,n,k,a[N],cnt=0,res,ans,dis[N],vis[N];
vector<ll> e[N];
void dfs_ans(int u,int fa,ll len){
    dis[u]=min(dis[u],len);
    if(dis[u]!=LLONG_MAX)
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v==fa)continue;
        dfs_ans(v,u,len+(vis[v]==0));
    }
}
void check(){
    int ku=k;
    int id1,id2;
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            int x=a[i],y=a[j];
            bool op=0;
            for(int ii=0;ii<e[x].size();ii++){
                if(e[x][ii]==y){
                    ku--;
                    op=1;
                    break;
                }
            }
            if(op==0){
                id1=x,id2=y;
            }
        }
    }
    if(ku!=2)return;
    for(int i=1;i<=n;i++){
        dis[i]=LLONG_MAX;
    }
    for(int i=1;i<=cnt;i++){
        vis[a[i]]=1;
        dis[a[i]]=0;
    }
    res=0;
    dfs_ans(id1,0,0);
    dfs_ans(id2,0,0);
    for(int i=1;i<=n;i++){
        if(dis[i]!=LLONG_MAX)res=max(res,dis[i]);
    }
    ans=min(ans,res);
    for(int i=1;i<=cnt;i++){
        vis[a[i]]=0;
    }
}
void dfs(int i,int tot){
    if(tot==k){
        check();
        return;
    }
    if(i==n+1)return;
    dfs(i+1,tot);
    cnt++;
    a[cnt]=i;
    dfs(i+1,tot+1);
    cnt--;
}
void work(){

    n=read();
    k=read();
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=LLONG_MAX;
    dfs(1,0);
    outt(ans);
    putchar('\n');
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();
    t=read();
    while(t--){
        work();
    }
    return 0;
}

