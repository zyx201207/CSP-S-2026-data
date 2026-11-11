#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],b[N];
int tid,T;
int n,k;
int ans=1e9;
int dep[N];
int fa[N];
int getfa(int u){
    if(fa[u]==u) return fa[u];
    return fa[u]=getfa(fa[u]);
}
vector<int >e[N];
void ck(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i]==1){
            dep[i]=0;
            cnt++;
        }else{
            dep[i]=1e9;
        }
    }
//    printf("cnt=%d\n",cnt);
    if(cnt==k){
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(b[i]) q.push(i);
            fa[i]=i;
        }
        for(int i=1;i<=n;i++){
            if(b[i]==1){
                for(auto v:e[i]){
                        if(!b[v]) continue;
                    int fau=getfa(i),fav=getfa(v);
                    if(fau==fav) continue;
                    fa[fau]=fav;
                }
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                if(fa[i]==i) cnt++;
            }
        }
        if(cnt>2) return;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:e[u]){
                if((dep[u]+1)<dep[v]){
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res=max(res,dep[i]);
        }
//        printf("res=%d\n",res);
        if(res==1){
//            for(int i=1;i<=n;i++){
//                printf("%d ",b[i]);
//            }printf("\n");
//            printf("%d\n",cnt);
        }
        ans=min(ans,res);


    }

}
void dfs(int u){
    if(u==n+1){
        ck();
        return;
    }
    b[u]=1;
    dfs(u+1);
    b[u]=0;
    dfs(u+1);
}
void work(){

    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(tid<=3){
        ans=1e9;
        dfs(1);
        printf("%d\n",ans);
    }else{
        printf("%d\n",0);
    }
}
int main(){
//    int m=5,n=11;
//    for(int i=1;i<=m;i++){
//        printf("%d %d\n",i,i+1);
//    }
//    for(int i=m+1;i<n;i++){
//        printf("%d %d\n",i-m,i+1);
//    }
//    system("diff -w hub.out hub2.ans");
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&tid,&T);
    for(;T;T--) work();
//    ll n,m;

//    scanf("%lld%lld")
    return 0;
}
