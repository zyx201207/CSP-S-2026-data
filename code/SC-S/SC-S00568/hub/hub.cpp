#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
const int maxm=2e6+10;
int head[maxn],nxt[maxm],to[maxm],cnt_ed=1;
void add_edge(int u,int v){
    nxt[++cnt_ed]=head[u],head[u]=cnt_ed,to[cnt_ed]=v;
}
bool vis[maxm];
int be[2],pos[2][maxn],ans[2][maxn];
int fa[maxn],dep[maxn];
int dfs(int x,int f,int de){
    int mx=x;fa[x]=f,dep[x]=de;
    for(int i=head[x];i;i=nxt[i]){
        if(vis[i>>1]) continue;
        int v=to[i];
        vis[i>>1]=true;
        int k=dfs(v,x,de+1);
        vis[i>>1]=false;
        if(dep[k]>dep[mx]) mx=k;
    }
    return mx;
}
int dfs1(int x,int id){
    int de=1;
    for(int i=head[x];i;i=nxt[i]){
        if(vis[i>>1]) continue;
        vis[i>>1]=true,de=max(de,dfs1(to[i],id)+1),vis[i>>1]=false;
    }
    pos[id][de]++;
    return de;
}
int n,k;

inline int getp(int res){
    int l=dfs(res,0,0),r=dfs(l,0,0);
    int qwq=r;
    for(int i=0;i<dep[r]/2;i++) qwq=fa[qwq];
    return qwq;
}
void solve(int id){
    int qwq=getp(be[id]);
    for(int i=0;i<=n;i++) ans[id][0]=pos[id][0]=0;
    dfs1(qwq,id);
    int cnt=0;
    for(int i=n;i>=1;i--){
        while(pos[id][i]>0) ans[id][++cnt]=i,pos[id][i]--;
    }
    // fprintf(stderr,"%d\n",id);
    // for(int i=1;i<=n;i++) fprintf(stderr,"%d ",ans[id][i]);
    // fprintf(stderr,"\npwp\n");
}
vector<int> respos,resed;

void bfs(int pos){
    vis[pos]=true;
    respos.push_back(pos);
    for(int i=0;i<respos.size();i++){
        int x=respos[i];
        vis[x]=true;
        for(int i=head[x];i;i=nxt[i]){
            if(vis[to[i]]) continue;
            resed.push_back(i>>1),respos.push_back(to[i]);
        }
    }
    for(int i=1;i<=n;i++) vis[i]=false;
}
int cntn=0;
void solve(){
    int a,b;
    scanf("%d%d",&n,&k);
    cnt_ed=1;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        add_edge(a,b),add_edge(b,a);
    }
    int awa=getp(1);respos.clear(),resed.clear();
    bfs(awa);
    // fprintf(stderr,"qwq\n");
    int sum=n,cnt=0;
    for(int i:respos){
        vis[i]=true,be[0]=to[i<<1],be[1]=to[i<<1|1];
        solve(0),solve(1);
        for(int i=1;i<k;i++) sum=min(sum,max(ans[0][i+1],ans[1][k-i+1]));
        vis[i]=false;
        if(cnt*n>1e7) break;
        cnt++;
    }
    printf("%d\n",sum);
    cntn+=n;
    // fprintf(stderr,"qwq %d\n",cnt);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        solve();
    }
    // fprintf(stderr,"%d\n",cntn);
}