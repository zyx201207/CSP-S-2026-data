#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
#define eb emplace_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;

const int N=503,M=5e5+7,inf=0x3f3f3f3f3f3f3f3f;

int cas,n,m,d,T,w[M];
int a[M],t[M],dis[1003][1003];
vector<PII> g[M];
bitset<N> arrive[N];
bool vis[1003];

bitset<N>b[M];
vector<int> gB[N];
int disB[N][N];
bool visB[N];

int aa[2][M],tt[2][M];

void dij(int st){
    priority_queue<PII>pq;
    dis[st][st]=0;
    pq.push({0,st});
    while(not pq.empty()){
        int u=pq.top().y;pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto xx:g[u]){
            int v=xx.x,w=xx.y;
            if(dis[st][u]+w<=dis[st][v]){
                dis[st][v]=dis[st][u]+w;
                pq.push({-dis[st][v],v});
            }
        }
    }
}


void dijB(int st){
    priority_queue<PII>pq;
    disB[st][st]=0;
    pq.push({0,st});
    while(not pq.empty()){
        int u=pq.top().y;pq.pop();
        if(visB[u])continue;
        visB[u]=1;
        for(auto v:gB[u]){
            if(disB[st][u]+1<=disB[st][v]){
                disB[st][v]=disB[st][u]+1;
                pq.push({-disB[st][v],v});
            }
        }
    }
}

int mk[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&cas,&n,&m,&d,&T);
    For(i,1,m){
        scanf("%lld",&w[i]);
    }
    if(1<=cas and cas<=11){//44pts
        For(i,1,n){
            int k;
            scanf("%lld",&k);
            For(j,1,k){
                scanf("%lld%lld",&a[j],&t[j]);
                For(l,1,j-1){
                    g[a[j]].eb(a[l],t[j]+t[l]);
                    g[a[l]].eb(a[j],t[j]+t[l]);
                    //printf("%lld-%lld ",a[j],a[l]);
                }
            }
        }
        For(i,1,m){
            /*printf("\n%lld->",i);
            for(auto xx:g[i]){
                printf("%lld ",xx.x);
            }puts("");*/
            For(j,1,m){
                dis[i][j]=inf;
                vis[j]=0;
            }
            dij(i);
        }
        while(T--){
            int l,r;scanf("%lld%lld",&l,&r);
            printf("%lld\n",w[l]+w[r]+dis[l][r]);
        }
        return 0;
    }
    if(12<=cas and cas<=19){
        int samet=-1;
        For(i,1,n){
            int k;
            scanf("%lld",&k);
            For(j,1,k){
                int a,t;
                scanf("%lld%lld",&a,&t);
                samet=t;
                b[a][i]=1;
                //b2[i][a[j]]=1;
                arrive[i]|=b[a];
            }
        }
        /*For(i,1,n){
            For(j,i+1,n){
                if((b[i]|b[j]).count()){
                    arrive[i][j]=1;
                }
            }
        }*/
        For(i,1,n){
            For(j,i+1,n){
                if(arrive[i][j]){
                    gB[i].eb(j);
                    gB[j].eb(i);
                }
            }
        }
        For(i,1,n){
            For(j,1,n){
                disB[i][j]=inf;
                visB[j]=0;
            }
            dijB(i);
        }
        while(T--){
            int l,r;scanf("%lld%lld",&l,&r);
            int mn=inf;
            For(i,1,n){
                For(j,1,n){
                    if(b[l][i] and b[r][j]){
                            //printf("%lld %lld | ",i,j);
                        mn=min(mn,disB[i][j]);
                    }
                }
            }
            printf("%lld\n",w[l]+w[r]+mn*samet*2);
        }
        return 0;
    }
    if(cas==21 or cas==22){
            For(i,1,m){
                tt[0][i]=tt[1][i]=mk[i]=inf;
            }
            int mn=inf;
        For(i,1,n){
            int k;
            scanf("%lld",&k);
            For(j,1,k){
                int a,t;
                scanf("%lld%lld",&a,&t);
                tt[n-1][a]=t;
                if(i==2 and tt[0][a]!=inf){
                    mk[a]=min(mk[a],t+tt[0][a]);
                    mn=min(mn,mk[a]);
                }
            }
        }while(T--){
            int l,r;scanf("%lld%lld",&l,&r);
            if(n==1){
                printf("%lld\n",w[l]+w[r]+tt[n-1][l]+tt[n-1][r]);
            }else{
                if(tt[0][l]!=inf and tt[0][r]!=inf or tt[1][l]!=inf and tt[1][r]!=inf)
                    printf("%lld\n",w[l]+w[r]+min(tt[0][l]+tt[0][r],tt[1][l]+tt[1][r]));
                else{
                    printf("%lld\n",w[l]+w[r]+mn+min(tt[0][l],tt[1][l])+min(tt[0][r],tt[1][r]));
                }
            }
        }
        return 0;
    }
    return 0;
}

/*
froepen
chzx_AT AK NGOI!!!!!
*/
