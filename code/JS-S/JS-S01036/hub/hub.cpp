#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,del##i##verme=int(n);i<del##i##verme;++i)
#define rep1(i,n) for(int i=1,parano##i##a=int(n);i<=parano##i##a;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define per1(i,n) for(int i=int(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
unsigned time_related_rand()
{
    return unsigned(std::chrono::steady_clock::now().time_since_epoch().count());
}
int c,t,n,k,u,v;
int cnt[1000006],dist[1000006],nxt[1000006],deg[1000006];
vector<int> con[1000006];
int dis2[1000006];
int q[1000006],ql,qr;
int trav(int x,int y,int thr)
{
    int s=(dis2[x]>=thr);
    for(int z:con[x]) if(z!=y) s+=trav(z,x,thr);
    return s;
}
vector<int> vc;
bool check(int x)
{
    vc.clear();
    rep1(i,n) if(dist[i]==x) vc.pb(i);
    if(vc.size()>2) return false;
    memset(dis2,0x3f,sizeof(int)*(n+2));
    int f=vc[0],g=vc[1];
    dis2[f]=dis2[g]=0;ql=1;qr=2;q[1]=f;q[2]=g;
    while(ql<=qr)
    {
        int y=q[ql++];
        for(int z:con[y]) if(dis2[z]==0x3f3f3f3f)
        {
            dis2[z]=dis2[y]+1;q[++qr]=z;
            if(dis2[z]>x) return false;
        }
    }
    return true;
}
void Q()
{
    cin>>n>>k;
    rep1(i,n)
    {
        cnt[i]=0;con[i].clear();deg[i]=0;dist[i]=0x3f3f3f3f;
    }
    rep1(i,n-1)
    {
        cin>>u>>v;con[u].pb(v);con[v].pb(u);++deg[u];++deg[v];
    }
    ql=1;qr=0;
    rep1(i,n) if(deg[i]==1)
    {
        q[++qr]=i;dist[i]=0;
    }
    while(ql<=qr)
    {
        int x=q[ql++];
        for(int y:con[x]) if((--deg[y])==1)
        {
            q[++qr]=y;nxt[y]=dist[y];dist[y]=dist[x]+1;
        }
        else if(deg[y]>=2)
        {
            dist[y]=dist[x]+1;
        }
    }
    int ret=n,cur=0;
    memset(cnt,0,sizeof(int)*(n+2));
    rep1(l,n) ++cnt[dist[l]];
    while(ret&&cur+cnt[ret-1]<=k) cur+=cnt[--ret];
    int ans=ret;
    if(c==11||c==12)
    {
        int L=-1,R=ans;
        while(R-L>1)
        {
            int M=(L+R)>>1;
            if(check(M)) R=M;
            else L=M;
        }
        cout<<R<<'\n';
      //  recheck(R);
        return;
    }
    rep1(x,n) for(int y:con[x]) if(y<x)
    {
        rep1(i,n) deg[i]=int(con[i].size());
        --deg[x];--deg[y];
        ql=1;qr=0;
        rep1(i,n) if(deg[i]<=1)
        {
            q[++qr]=i;dis2[i]=0;
        }
        while(ql<=qr)
        {
            int xx=q[ql++];
            for(int yy:con[xx]) if(!((yy==y&&xx==x)||(yy==x&&xx==y))) if((--deg[yy])==1)
            {
                q[++qr]=yy;dis2[yy]=dis2[xx]+1;
            }
        }
        memset(cnt,0,sizeof(int)*(n+2));
        ret=n,cur=0;
    //    rep1(l,n) cout<<dis2[l]<<" ";
    //    cout<<endl;
        rep1(l,n) ++cnt[dis2[l]];
        while(ret&&cur+cnt[ret-1]<=k) cur+=cnt[--ret];
        if(cur==k)
        {
            int cnti=trav(x,y,ret);
           // cout<<"> "<<cnti<<endl;
            if(cnti==k||cnti==0) ++ret;
        }
        ans=min(ans,ret);
    }
    cout<<ans<<'\n';
}
int main()
{
    #ifndef DEBUG
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;while(t--)Q();
    return 0;
}
/*
_i__e: _i__ ___ re_e__er _e
__i_ i_ _ _e__ __ere ___ _e__er_ e__e__ __e_e _r__ __e __r_ "reviver" _re re____e_ __ ___er_i_e_.
__r e_____e, __r__ _i_e "river" _re_'_ _____e_, ___ __r__ _i_e "____" _i____e_r.
___e ___ ___ re__ver __i_ _e__.
*/