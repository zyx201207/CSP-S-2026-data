#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+8,Q=1e5+12;
map<int,ll> wld[N];
int c,n,m,d,q;
int sz[M];
ll wll[N][N],w[M],dis[N][N];
int k[N],xx[Q],yy[Q],dtl[M][22];
struct Edge{
    int to,nxt;
}e[N*N];
int hd[N],nE;
void addEdge(int u,int v){
    e[++nE]=(Edge){v,hd[u]};
    hd[u]=nE;
}
void solveFW(){
    memset(wll,0x3F,sizeof(wll));
    for(int i = 1;i <= m;i++){
        for(int l = 1;l <= sz[i];l++){
            for(int r = l+1;r <= sz[i];r++){
                int lp=dtl[i][l],rp=dtl[i][r];
                if(wld[lp][i]!=0 && wld[rp][i]!=0)wll[lp][rp]=wll[rp][lp]=min(wll[lp][rp],wld[lp][i]+wld[rp][i]);
            }
        }
    }
    for(int i = 1;i <= n;i++)wll[i][i]=0;
    for(int mid = 1;mid <= n;mid++){
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                wll[i][j]=min(wll[i][j],wll[mid][i]+wll[mid][j]);
                wll[j][i]=wll[i][j];
            }
        }
    }
    for(int qid = 1;qid <= q;qid++){
        int du=xx[qid],dv=yy[qid];
        ll ans=0x3F3F3F3F3F3F3F3F;
        for(int pu = 1;pu <= sz[du];pu++){
            int lu=dtl[du][pu];
            for(int pv = 1;pv <= sz[dv];pv++){
                int lv=dtl[dv][pv];
                ans=min(ans,wld[lu][du]+wll[lu][lv]+wld[lv][dv]);
            }
        }
        cout<<w[du]+ans+w[dv]<<'\n';
    }
}
void solveBFS(){
    ll T=wld[1][1];
    for(int i = 1;i <= m;i++){
        for(int l = 1;l <= sz[i];l++){
            for(int r = l+1;r <= sz[i];r++){
                int lp=dtl[i][l],rp=dtl[i][r];
                if(wld[lp][i]!=0 && wld[rp][i]!=0){
                    addEdge(lp,rp);
                    addEdge(rp,lp);
                }
            }
        }
    }
    for(int s = 1;s <= n;s++){
        memset(dis[s],-1,sizeof(dis[s]));
        queue<int> q;
        q.push(s);
        dis[s][s]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i = hd[u];i;i=e[i].nxt){
                int v=e[i].to;
                if(dis[s][v]==-1){
                    dis[s][v]=dis[s][u]+1;
                    q.push(v);
                }
            }
        }
    }
    for(int qid = 1;qid <= q;qid++){
        int du=xx[qid],dv=yy[qid];
        ll ans=0x3F3F3F3F3F3F3F3F;
        for(int pu = 1;pu <= sz[du];pu++){
            int lu=dtl[du][pu];
            for(int pv = 1;pv <= sz[dv];pv++){
                int lv=dtl[dv][pv];
                ans=min(ans,1ll+dis[lu][lv]);
            }
        }
        cout<<w[du]+2ll*T*ans+w[dv]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++)cin>>w[i];
    for(int i = 1;i <= n;i++){
        cin>>k[i];
        for(int j = 1;j <= k[i];j++){
            int a,t;
            cin>>a>>t;
            wld[i][a]=t;
            dtl[a][++sz[a]]=i;
        }
    }
    for(int i = 1;i <= q;i++)cin>>xx[i]>>yy[i];
    if(12<=c && c<=19){
        solveBFS();
    }
    else{
        solveFW();
    }
    return 0;
}
