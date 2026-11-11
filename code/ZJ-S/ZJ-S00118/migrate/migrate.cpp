#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;
int c,t,n,d;
ll res;
ll x[N];

//namespace workA{ // 8
//    bool check(){ return c==11 || c==12; }
//    void calc(){
//
//    }
//}
namespace workB{ // 8
    bool check(){ return c==13 || c==14; }
    void calc(){
        for (int i=1;i<=n;++i){
            int p=lower_bound(x+1,x+i,x[i]-d)-x;
            if (p<n && x[p+1]<=x[i]+d) res+=p-(lower_bound(x+1,x+p,x[p+1]-d)-x);
        }
    }
}
namespace work1{ // rnd(0,40)
    bool check(){ return c<=10; }
    int dis[N],cnt[N];
    void dijk(int st){
        queue<int> q;
        q.push(st),dis[st]=0,cnt[st]=1;
        while (!q.empty()){
            int u=q.front();  q.pop();
            for (int v=lower_bound(x+1,x+u,x[u]-d)-x;v<=n && x[v]<=x[u]+d;++v){
                if (dis[u]+1<dis[v]) dis[v]=dis[u]+1,cnt[v]=cnt[u],q.push(v);
                else if (dis[u]+1==dis[v]) cnt[v]+=cnt[u];
            }
        }
    }
    void calc(){
        for (int i=1;i<=n;++i){
            memset(dis,0x3f,sizeof dis);
            memset(cnt,0,sizeof cnt);
            dijk(i);
            for (int j=i+1;j<=n;++j){
                if (cnt[j]==2) ++res;
            }
        }
    }
}
int main(){ // rnd(8,48)
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t--){
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;++i) scanf("%lld",x+i);
        res=0;
//        if (workA::check()) workA::calc();
        if (workB::check()) workB::calc();
        else if (work1::check()) work1::calc();
        printf("%lld\n",res);
    }
    return 0;
}

