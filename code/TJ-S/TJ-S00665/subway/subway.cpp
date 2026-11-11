#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

template <typename T> bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Solve{
    const int MAXN=505,MAXM=5e4+5,MAXD=25;
    const int MAXV=MAXM,MAXE=MAXM;
    int _,n,m,d,q;
    int a[MAXM],out[MAXV];
    // std::vector<int> t[MAXN];
    int t[MAXN][MAXM];
    std::vector<int> b[MAXM];
    int next[MAXN][MAXM];
    int e,head[MAXV];
    struct edge{int to,next;}E[MAXE<<1];
    void add(int x,int y){E[++e]=(edge){y,head[x]};head[x]=e;}

    namespace Force{
        void solve(){

        }
    }
    namespace Better{
        int dis[MAXN][MAXM][2];

        struct rec{
            int i,j,f,dis;
            friend bool operator>(const rec &a,const rec &b){return a.dis>b.dis;}
            friend bool operator<(const rec &a,const rec &b){return b>a;} 
        };
        const int INF=0x3f3f3f3f;
        void f(int p){
            std::priority_queue<rec> Q;

            for(int i=1;i<=m;i++) for(int j:b[i]) for(int k=0;k<=1;k++) dis[j][i][k]=INF;
            for(int i:b[p]) dis[i][p][1]=t[i][p],Q.push((rec){i,p,0,t[i][p]});
            while(!Q.empty()){
                rec x=Q.top(); 
                Q.pop();
                if(x.f){
                    for(int y:b[x.j]){
                        if(tense(dis[y][x.j][false],x.dis+t[y][x.j]+t[x.i][x.j])) Q.push((rec){y,x.j,false,dis[y][x.j][false]});
                    }
                }
                if(next[x.i][x.j]){
                    if(tense(dis[x.i][next[x.i][x.j]][true],x.dis)) Q.push((rec){x.i,next[x.i][x.j],true,x.dis});
                }
            }
        }
        void solve(){
            while(q--){
                int x,y;
                scanf("%d%d",&x,&y);
                f(x);
                int ans=INF;
                for(int i:b[y]) tense(ans,dis[i][y][1]+t[i][y]);
                printf("%d\n",a[x]+a[y]+ans);
            }
        }
    }
    void solve(){
        scanf("%d%d%d%d%d",&_,&n,&m,&d,&q);
        for(int i=1;i<=m;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&out[i]);

            int last=0;
            for(int j=1;j<=out[i];j++){
                int y,z;
                scanf("%d%d",&y,&z);
                if(last) next[i][last]=y;
                last=y;
                b[y].push_back(i);
                
                t[i][y]=z;
            }
        }
        Better::solve();
        // Force::solve();
    }
}

int main(){
    freopen("subway.in","r",stdin);
    // freopen("subway2.in","r",stdin);
    freopen("subway.out","w",stdout);

    Solve::solve();

    return 0;
}