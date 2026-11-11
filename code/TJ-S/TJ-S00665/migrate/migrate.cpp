#include <cstdio>
#include <algorithm>

template <typename T> bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Solve{
    int _,T;
    int n,d;
    const int MAXN=2e6+5;
    int a[MAXN];

    namespace Force{
    
        int f[MAXN];
        const int INF=0x3f3f3f3f;
        void solve(){
            int ans=0;
            for(int x=1;x<n;x++){
                for(int y=x+1;y<=n;y++){
                    int res=INF,resc=0;
                    for(int s=0;s<(1<<(y-x-1));s++){
                        for(int i=x+1,j=0;i<=y-1;i++,j++) f[i]=(s>>j)&1;
                        bool ok=true;
                        int last=a[x];
                        for(int i=x+1;i<=y-1;i++) if(f[i]){
                            if(a[i]-last>d) ok=false;
                            last=a[i];
                        }
                        if(a[y]-last>d) ok=false;
                        if(ok){
                            int c=0;
                            for(int i=x+1;i<=y-1;i++) if(f[i]) c++;
                            if(tense(res,c)) resc=1;
                            else if(res==c) resc++;
                        }
                    }
                    if(resc==2) ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    void solve(){
        scanf("%d%d",&_,&T);
        while(T--){
            scanf("%d%d",&n,&d);
            for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            Force::solve();
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    Solve::solve();

    return 0;
}