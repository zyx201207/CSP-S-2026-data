#include<bits/stdc++.h>
using namespace std;
#define int long long
struct qiqi{
    int st,tim;
};
const int N=5e5+15,NN=555;
int c,n,m,d,qus,w[N],k[NN],xx,yy,ans,minn[N];
vector<qiqi>a[N];
vector<int>sta[N];
inline void f(int fr,int nw,int tag,int num){
    if(nw==tag){
        return ;
    }
    for(int i=0;i<sta[nw].size();++i){
        int tv=num;
        int nl=sta[nw][i];
        for(int j=0;j<a[nl].size();++j){
            int ot=a[nl][j].st;
            if(ot==nw){
                tv+=a[nl][j].tim;
                break;
            }
        }
        for(int j=0;j<a[nl].size();++j){
            int ot=a[nl][j].st;
            if(ot==nw){
                continue;
            }
            if(tv+a[nl][j].tim>=minn[ot]){
                continue;
            }
            tv+=a[nl][j].tim;
            minn[ot]=tv;
            f(nl,ot,tag,tv);
            tv-=a[nl][j].tim;
        }
    }
    return ;
}
inline void sol(int x,int y){
    f(0,x,y,0);
    ans=ans+minn[y];
    return;
}
signed main(){
//freopen("subway2.in","r",stdin);
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qus);
    for(int i=1;i<=m;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;++i){//line i
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];++j){//线路i的站台走到地铁站xx站厅需要yy
            scanf("%lld%lld",&xx,&yy);
            a[i].push_back({xx,yy});
            sta[xx].push_back(i);
        }
    }
    while(qus--){
        memset(minn,0x5f5f5f5f,sizeof(minn));
        scanf("%lld%lld",&xx,&yy);
        ans=w[xx]+w[yy];
        sol(xx,yy);
        printf("%lld\n",ans);
    }
    return 0;
}
