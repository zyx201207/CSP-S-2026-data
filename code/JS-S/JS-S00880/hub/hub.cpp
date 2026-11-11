#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int ll
#define db double
#define ldb long db
#define rep(a,b,c) for(signed a=b;a<=c;a++)
#define vep(a,b,c) for(signed a=b;a>=c;a--)
#define mdI int mid=(l+r)>>1
#define pbI push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) (x)&(-(x))
#define inf 1000000000//000000000
#define MOD 1000000007//998244353
#define MAXN 1000010
#define gc getchar
void chmd(int&x,int y){x+=y;if(x>=MOD)x-=MOD;}
// void chmd(ll&x,ll y){x+=y;if(x>=MOD)x-=MOD;}
void chmx(int&x,int y){x=max(x,y);}
void chmi(int&x,int y){x=min(x,y);}
ll qp(ll a,ll b,ll p=MOD){ll rs=1,bs=a;while(b){if(b&1)rs=rs*bs%p;bs=bs*bs%p;b>>=1;}return rs;}
int qread(){
    char o=gc();int f=1,x=0;
    for(;!isdigit(o);o=gc())if(o=='-')f=-1;
    for(;isdigit(o);o=gc())x=x*10+o-'0';
    return f*x;
}
bool FLA;
int n,k,d;
vector<int>vec[MAXN];
int dis[2][MAXN];
void dfs(int u,int fa,int *dis){
    for(auto v:vec[u]){
        if(v==fa)continue;
        dis[v]=dis[u]+1;
        dfs(v,u,dis);
    }
}
bool bel[MAXN];
int he[MAXN];
int dfs1(int u,int fa,bool nd){
    he[u]=0;
    int ans=0;
    for(auto v:vec[u]){
        if(v==fa||bel[v]!=nd)continue;
        ans+=dfs1(v,u,nd);
        chmx(he[u],he[v]+1);
    }
    return ans+(he[u]>=d);
}
bool check(int D){d=D;
    int ans=1e9;
    rep(r1,1,n){
        dis[0][r1]=0;dfs(r1,0,dis[0]);
        rep(i,1,n)bel[i]=0;
        chmi(ans,dfs1(r1,0,0));
        rep(r2,r1+1,n){
            dis[1][r2]=0;dfs(r2,0,dis[1]);
            rep(i,1,n){
                bel[i]=(dis[0][i]>dis[1][i]);
            }
            chmi(ans,dfs1(r1,0,0)+dfs1(r2,0,1));
        }
    }
    return ans<=k;
}
void cls(){
    rep(i,1,n)vec[i].clear();
}
int CNT=0;
void solve(){
    CNT++;
    cin>>n>>k;
    rep(i,1,n-1){
        int u=qread(),v=qread();
        vec[u].pbI(v);vec[v].pbI(u);
    }
    int l=0,r=n-1,ans=0;
    while(l<=r){
        mdI;
        if(check(mid)){
            r=mid-1;ans=mid;
        }
        else{l=mid+1;}
    }
    cout<<ans<<endl;
    cls();
}
bool FLB;
signed main(){
    cerr<<((&FLB)-(&FLA))/1024.0/1024<<endl;
    // freopen("a.in","r",stdin);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--)solve();
}