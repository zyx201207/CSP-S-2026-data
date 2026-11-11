#include<bits/stdc++.h>
using namespace std;
using i64=long long;
template<class T>
void Cmin(T &x,const T& y){ x=(x<y?x:y); }
template<class T>
void Cmax(T &x,const T& y){ x=(x<y?y:x); }
const int N=4e3+5;
int n,k,buc[N],top,dis[N],tmp[N],pre[N],ptmp,pstk;
struct Memory{
    int *x,y;
    void Back(){ *x=y; }
}stk[10000005];
void Back(){
    while(pstk>tmp[ptmp]) stk[pstk--].Back();
    --ptmp;
}
vector<int> G[N];
void Modify(int x,int y){
    stk[++pstk]={dis+x,dis[x]};
    stk[++pstk]={buc+dis[x],buc[dis[x]]};
    stk[++pstk]={buc+y,buc[y]};
    stk[++pstk]={&top,top};
    --buc[dis[x]],++buc[dis[x]=y];
    while(!buc[top]) --top;
}
void DFS(int u,int fu,int d){
    ++buc[dis[u]=d],pre[u]=fu;
    // printf("%d %d\n",u,dis[u]);
    for(int v:G[u])
        if(v!=fu) DFS(v,u,d+1);
}
void Init(int s){
    ptmp=pstk=top=0;
    for(int i=0;i<n;++i) buc[i]=0;
    DFS(s,0,0);
    while(buc[top+1]) ++top;
}
void Push(int s){
    tmp[++ptmp]=pstk;
    Modify(s,0);
    queue<int> q;
    q.push(s);
    // printf("Push(%d)\n",s);
    while(!q.empty()){
        int u=q.front();
        // printf("%d\n",u);
        q.pop();
        for(int v:G[u]){
            // printf("%d %d %d %d\n",u,v,dis[u],dis[v]);
            if(dis[v]>dis[u]+1){
                stk[++pstk]={pre+v,pre[v]},pre[v]=u;
                Modify(v,dis[u]+1);
                q.push(v);
            }
        }
    }
}
void Work(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) G[i].clear();
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if(n==k){
        puts("0");
        return ;
    }
    int u=0,v=0,val=n;
    for(int x=1;x<=n;++x){
        Init(x);
        for(int y=x+1;y<=n;++y){
            Push(y);
            if(top<val) val=top,u=x,v=y;
            Back();
        }
    }
    Init(u),Push(v);
    // printf("%d %d %d\n",u,v,val);
    for(int i=3;i<=k;++i){
        int y=0,val=0;
        for(int x=1;x<=n;++x){
            if(dis[x]>val) y=x,val=dis[x];
        }
        // printf("%d %d\n",y,val);
        while(dis[y]>1) y=pre[y];
        Push(y);
    }
    printf("%d\n",top);
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int sid,T;
    cin>>sid>>T;
    while(T--) Work();
    fclose(stdin),fclose(stdout);
    return 0;
}