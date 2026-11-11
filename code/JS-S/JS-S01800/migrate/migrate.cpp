#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+15;
int c,t,n,d,x[N],dis[N],tot[N],ans;
bool vis[N];
struct qiqi{
    int u,num;
};
inline void _cle(){
    memset(vis,0,sizeof(vis));
    return ;
}
queue<qiqi>q;
inline void f(int nw){
    q.push({nw,0});
    vis[nw]=1;
    while(q.size()){
        int u=q.front().u,num=q.front().num;
        q.pop();
        for(int i=u+1;i<=n;++i){
            if(i==nw){
                continue;
            }
            int dst=x[i]-x[u];
            if(dst>d){
                break;
            }
            if(vis[i]){
                if(num+1==dis[i]){
                    ++tot[i];
                }
                continue;
            }
            tot[i]=1;
            vis[i]=1;
            dis[i]=num+1;
            q.push({i,num+1});
        }
    }
    return ;
}
inline void sol(int fr){
    dis[fr]=0;
    f(fr);
//    for(int j=1;j<=n;++j){
//        cout<<fr<<" to "<<j<<":"<<dis[j]<<" , "<<tot[j]<<"\n";
//    }
    for(int i=1;i<=n;++i){
        if(tot[i]==2){
            ++ans;
            tot[i]=0;
        }
    }
    return ;
}
signed main(){
//freopen("migrate2.in","r",stdin);
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        memset(x,0,sizeof(x));
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;++i){//from i
            _cle();
            sol(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
