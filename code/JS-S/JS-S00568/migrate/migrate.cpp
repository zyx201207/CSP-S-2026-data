#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back

const int N=2e6+9;
inline int lowbit(int x){return x&(-x);}
inline void chkmin(int &x,int y){x=x<y?x:y;}
inline void chkmax(int &x,int y){x=x>y?x:y;}
inline void chkmin(ll &x,ll y){x=x<y?x:y;}
inline void chkmax(ll &x,ll y){x=x>y?x:y;}

#define int long long
int n,d,a[N],to[N],as[N],f[N],g[N],h[N],th[N],tf[N];
void sub0(){
    for(int i=n-1;i>=1;--i){
        if(to[i]<=i){
            continue;
        }
        // calculate th
        if(to[i]==i+1){th[i]=1+th[i+1];}
        else th[i]=tf[to[i]-1]+to[i]-i;

        // calculate tf
        if(to[i+1]>to[i]){
            if(to[i]+1==to[i+1]){tf[i]=th[to[i+1]]+1;}
            else tf[i]=tf[to[i+1]-1]+(to[i+1]-to[i]);
        }

        // calculate h
        if(to[i]==i+1){h[i]=h[i+1];}
        else if(to[i]==i+2){h[i]=f[i+1];}
        else h[i]=g[to[i]-2];

        // calculate f
        if(to[i]>i+1){
            int tL=to[i]+1,tR=to[i+1];
            if(tL+2<=tR){
                f[i]+=g[tR-2];
            }else if(tL+1<=tR) f[i]+=f[tL];
            else if(tL==tR) f[i]+=h[tL];
        }
        if(to[i]>i+1){
            f[i]+=max(0ll,to[i]-(i+1));
            int tL=i+2,tR=to[i];
            if(tL==tR) f[i]+=th[tL];
            else f[i]+=tf[tR-1];
        }

        // calculate g
        if(n-i+1>=3){

        if(to[i+1]>i+2){
            int tL=to[i+1]+1,tR=to[i+2];
            if(tL+2<=tR){
                g[i]+=g[tR-2];
            }else if(tL+1<=tR) g[i]+=f[tL];
            else if(tL==tR) g[i]+=h[tL];
        } g[i]+=max(0ll,to[i+1]-max(i+2,to[i]));
        if(to[i+1]>max(i+2,to[i])){
            g[i]+=max(0ll,to[i+1]-max(i+2,to[i]));
            int tL=max(i+2,to[i])+1,tR=to[i+1];
            if(tL==tR) f[i]+=th[tL];
            else f[i]+=tf[tR-1];
        }

        }
    }
    int ans=0;
    for(int i=n;i>=1;--i){
        if(to[i]==i) continue;
        else if(to[i]==i+1){as[i]=as[i+1]; continue;}
        else if(to[i]==i+2){as[i]=f[i+1]; continue;}
        else as[i]=g[to[i]-2];
    }
    for(int i=1;i<=n;++i){
        ans+=as[i];
        //cout<<i<<' '<<to[i]<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<' '<<as[i]<<endl;
    }
    cout<<ans<<'\n';
}
#define INF (1e9)
int dis[N],cnt[N],dp[N];
void sub1(){
    for(int i=1;i<=n;++i){
        for(int j=i;j>=1;--j)
            if(a[j]+d>=a[i]) to[i]=j;
            else break;
    }
    int ans=0;
    for(int u=1;u<=n;++u){
        for(int i=1;i<=n;++i) dis[i]=INF;
        for(int i=1;i<=n;++i) cnt[i]=dp[i]=0;
        int nw=u,mi=0; dis[u]=0; cnt[0]=1;
        dp[0]=1;
        for(int v=u+1;v<=n;++v){
            while(nw<to[v]){cnt[dis[nw]]-=dp[nw];
                if(dis[nw+1]>dis[nw]) mi=dis[nw+1];
                ++nw;
            }
            if(mi==INF) break;
            dis[v]=mi+1; dp[v]=cnt[mi];
            if(cnt[mi]==2) ++ans;
            cnt[dis[v]]+=dp[v];
            //cout<<u<<' '<<v<<' '<<dis[v]<<' '<<dp[v]<<endl;
        }
    } cout<<ans<<'\n';
}
void sub2(){
    int d=to[1]-1;
    if(d<=1) cout<<0<<'\n';
    else cout<<max(0ll,n-(2*d-1))<<'\n';
}
void Mian(int TestCase){
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>a[i];

    if(TestCase<=10) return sub1(),void();
    bool flgA=1;
    for(int i=2;i<n;++i) if(a[i+1]-a[i]!=a[i]-a[i-1]) flgA=0;
    if(11<=TestCase && TestCase<=12) return sub2(),void();
}
void Mianclr(){
    for(int i=1;i<=n;++i) f[i]=g[i]=as[i]=to[i]=th[i]=tf[i]=0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=0,T=1; cin>>c>>T;
    while(T--){
        Mian(c);
        Mianclr();
    }
}
