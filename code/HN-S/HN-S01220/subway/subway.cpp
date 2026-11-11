#include<bits/stdc++.h>
using namespace std;
int csd,n,m,d,Q,T;
int w[500003];
bool g[500003],ch[200000003];
struct aaa{
    int km;
    vector<int>a,t;
}lx[503];
vector<int>e[500003];
long long bfs(int u,int mb){
    memset(g,0,sizeof(g));
    queue<pair<int,int> >q;
    q.push({u,0});
    g[u]=true;
    int i;
    while(q.empty()==false){
        u=q.front().first;
        int w=q.front().second;
        q.pop();
        for(i=0;i<e[u].size();i++){
            int v=e[u][i];
            if(g[v]==false){
                g[v]=true;
                q.push({v,w+1});
                if(v==mb)
                    return (long long)(w+1)*T*2;
            }
        }
    }
}
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int i,j,k;
    scanf("%d%d%d%d%d",&csd,&n,&m,&d,&Q);
    for(i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&lx[i].km);
        for(j=1;j<=lx[i].km;j++){
            int u,v;
            scanf("%d%d",&u,&v);
            lx[i].a.push_back(u);
            lx[i].t.push_back(v);
            T=v;
        }
    }
    if(csd>=12&&csd<=19){
        for(i=1;i<=n;i++){
            for(j=0;j<lx[i].km;j++){
                int u=lx[i].a[j];
                for(k=0;k<lx[i].km;k++){
                    int v=lx[i].a[k];
                    if(u==v)
                        continue;
                    if(ch[u*(m-1)+v-1]==false&&ch[v*(m-1)+u-1]==false){
                        e[u].push_back(v);
                        e[v].push_back(u);
                        ch[u*(m-1)+v-1]=false;
                    }
                }
            }
        }
        for(i=1;i<=Q;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            long long ans=bfs(u,v)+w[u]+w[v];
        }
    }
    else{
        long long f[1003][1003];
        memset(f,0x3f,sizeof(f));
        for(i=1;i<=n;i++){
            for(j=0;j<lx[i].km;j++){
                int u=lx[i].a[j];
                for(k=0;k<lx[i].km;k++){
                    int v=lx[i].a[k];
                    if(u==v)
                        continue;
                    f[u][v]=lx[i].t[j]+lx[i].t[k];
                    f[v][u]=lx[i].t[j]+lx[i].t[k];
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<i;j++){
                for(k=1;k<=m;k++){
                    if(i==k||j==k)
                        continue;
                    f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
                    f[j][i]=f[i][j];
                }
            }
        }
        for(i=1;i<=Q;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            long long ans=f[u][v]+w[u]+w[v];
            printf("%lld\n",ans);
        }
    }

    return 0;
}