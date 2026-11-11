#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f;
int C,T,n,k,f[25][N],b[N],dep[N],ans,s,t,fa,mx[N],nmx[N],d[N],f1[N],f2[N];
vector<int> e[N];
void dfs0(int u,int fa){
    f[0][u]=fa; dep[u]=dep[fa]+1;
    for(int i=1;i<=20;i++)
        f[i][u]=f[i-1][f[i-1][u]];
    for(int v:e[u]){
        if(v!=fa){
            dfs0(v,u);
        }
    }
    return;
}
void dfs(int u,int fa,int s,int op){
    b[u]=op;
    for(int v:e[u]){
        if(v!=fa&&((s>>(v-1))&1)){
            dfs(v,u,s,op);
        }
    }
    return;
}
int LCA(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int t=dep[u]-dep[v];
    for(int i=0;i<=20;i++){
        if((t>>i)&1) u=f[i][u];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(f[i][u]!=f[i][v]){
            u=f[i][u];
            v=f[i][v];
        }
    }
    return f[0][u];
}
int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
void dfs20(int u,int fa){
    d[u]=d[fa]+1;
    for(int v:e[u]){
        if(v==fa) continue;
        dfs20(v,u);
    }
    return;
}
void dfs21(int u,int fa){
    d[u]=d[fa]+1; f[0][u]=fa;
    for(int v:e[u]){
        if(v==fa) continue;
        dfs21(v,u);
        int nw=mx[v];
        if(nw+1>=mx[u]){
            nmx[u]=mx[u];
            mx[u]=nw+1;
        }else if(nw+1>nmx[u]){
            nmx[u]=nw+1;
        }else if(nmx[v]+1>nmx[u]){
            nmx[u]=nmx[v]+1;
        }
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        if(k==2){
            for(int i=1;i<=n;i++) nmx[i]=mx[i]=0;
            dfs20(1,0);
            for(int i=1;i<=n;i++)
                if(d[i]>d[s]) s=i;
            dfs21(s,0);
            for(int i=1;i<=n;i++)
                if(d[i]>d[t]) t=i;
            // if(k==1){
            //     printf("%d\n",d[t]/2);
            //     for(int i=1;i<=n;i++) e[i].clear();
            //     continue;
            // }
            ans=INF;
            int nw=t,l1=1,l2=d[t]-1,cnt=0;
            // cout<<s<<' '<<t<<" "<<d[t]<<endl;
            while(nw!=s){
                cnt++;
                // cout<<nw<<" "<<nmx[nw]<<" "<<l2<<endl;
                f1[cnt]=nmx[nw]+l1;
                f2[cnt]=nmx[nw]+l2;
                l1++; l2--;
                nw=f[0][nw];
            }
            cnt++;
            f1[cnt]=nmx[s]+l1;
            f2[cnt]=nmx[s];
            for(int i=2;i<=cnt;i++) f1[i]=max(f1[i-1],f1[i]);
            for(int i=cnt-1;i>=1;i--) f2[i]=max(f2[i+1],f2[i]);
            nw=t;
            for(int i=1;i<cnt;i++){
                // cout<<nw<<" "<<l1<<" "<<l2<<" "<<f1[i]<<" "<<f2[i+1]<<endl;
                ans=min(ans,max((f1[i]+1)/2,(f2[i+1]+1)/2));
                nw=f[0][nw];
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++) e[i].clear();
            continue;
        }
        dfs0(1,0);
        ans=INF;
        // cout<<dis(2,5)<<endl;
        for(int s=0;s<=(1<<n)-1;s++){
            if(__builtin_popcount(s)!=k) continue;
            for(int i=1;i<=n;i++)b[i]=0;
            int nw=0;
            for(int i=1;i<=n;i++){
                if(!b[i]&&((s>>(i-1))&1)) nw++,dfs(i,0,s,nw); 
            }
            if(nw>2) continue;
            int tmp=0;
            // cout<<s<<":\n";
            for(int i=1;i<=n;i++){
                if((s>>(i-1))&1) continue;
                int nw=INF;
                for(int j=1;j<=n;j++){
                    if((s>>(j-1))&1) nw=min(nw,dis(i,j));
                }
                tmp=max(tmp,nw);
                // cout<<nw<<" "<<tmp<<endl;
            }
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) e[i].clear();
    }
    return 0;
}