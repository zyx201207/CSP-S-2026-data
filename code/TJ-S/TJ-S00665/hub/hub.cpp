#include <cstdio>
#include <algorithm>
#include <vector>

template <typename T> bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Solve{
    int n,k;
    const int MAXV=2e6+5,MAXE=MAXV<<1,MAXN=MAXV;
    int e,head[MAXV];
    struct edge{int to,next;}E[MAXE];
    void add(int x,int y){E[++e]=(edge){y,head[x]};head[x]=e;}

    namespace Force{
        std::vector<int> G[MAXN];
        int pre[MAXN],dep[MAXN];
        void dfs(int x){
            for(int y:G[x]) if(y!=pre[x]){
                pre[y]=x;
                dep[y]=dep[x]+1;
                dfs(y);
            }
        }


        int fa[MAXN];
        int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
        void merge(int x,int y){
            x=find(x),y=find(y);
            if(x==y) return;
            fa[x]=y;

        }

        int f[MAXN];


        int dist(int x,int y){
            int ans=0;
            while(x!=y){
                if(dep[x]<dep[y]) std::swap(x,y);
                x=fa[x];
                ans++;
            }
            return ans;
        }

        int d[MAXN];
        const int INF=0x3f3f3f3f;
        void solve(){
            int ans=INF;
            for(int s=0;s<(1<<n);s++){
                int c=0;
                // printf("%d\n",s);


                for(int i=1;i<=n;i++) if(s>>(i-1)&1) c++;
                if(c!=k) continue;
                for(int i=1;i<=n;i++) f[i]=false;
                for(int i=1;i<=n;i++) fa[i]=i;
                for(int i=1;i<=n;i++) if((s>>(i-1)&1)){
                    for(int j=head[i];j;j=E[j].next){
                        // printf("%d\n",j);
                        // fflush(stdout);
                        merge(i,E[j].to);

                    }
                }

                int cnt=0;
                for(int i=1;i<=n;i++) if(s>>(i-1)&1){
                    if(!f[find(i)]) cnt++,f[find(i)]=true;
                }

                if(cnt>2) continue;
                for(int i=1;i<=n;i++) G[i].clear();
                for(int i=1;i<=n;i++) if(s>>(i-1)&1){
                    for(int j=head[i];j;j=E[j].next) G[i].push_back(E[j].to);
                }
            // return ;

                for(int i=1;i<=n;i++) pre[i]=0;
                for(int i=1;i<=n;i++) if((s>>(i-1)&1)&&!pre[i]) dfs(i); 
                for(int i=1;i<=n;i++) d[i]=INF;
                for(int i=1;i<=n;i++) for(int j:G[i]) tense(d[i],dist(i,j));
                int res=0;
                for(int i=1;i<=n;i++) relax(res,d[i]);
                tense(ans,res);

            }
            printf("%d\n",ans);
        }
    }
    void solve(){
        int _,T;
        scanf("%d%d",&_,&T);
        while(T--){
            for(int i=1;i<=e;i++) E[i].next=E[i].to=0;
            e=0;
            for(int i=1;i<=n;i++) head[i]=0;
            scanf("%d%d",&n,&k);
            for(int i=1;i<n;i++){
                int x,y;
                scanf("%d%d",&x,&y);
                // printf("%d %d\n",x,y);
                add(x,y),add(y,x);
            }
            // printf("%d %d",head[1],E[1].next);
            // return;
            // for(int i=1;i<=n;i++) for(int j=head[i];j;j=E[j].next){
            //     printf("%d -> %d\n",i,E[j].to);
            //     // break;
            // }
            Force::solve();
            return;
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
        // puts("1");
    Solve::solve();

    return 0;
}