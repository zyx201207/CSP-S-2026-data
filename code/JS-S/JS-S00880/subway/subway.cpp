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
#define inf 1000000000
#define MOD 1000000007//998244353
#define MAXN 520010
#define gc getchar
void chmd(int&x,int y){x+=y;if(x>=MOD)x-=MOD;}
void chmd(ll&x,ll y){x+=y;if(x>=MOD)x-=MOD;}
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
void chmi(ll&x,ll y){x=min(x,y);}
int _,n,m,_1,q;
int w[MAXN];
vector<pii>vec[MAXN];
ll dis[520][520];
bool FLB;
signed main(){
    cerr<<((&FLB)-(&FLA))/1024.0/1024<<endl;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>_1>>q;
    rep(i,1,m)w[i]=qread();
    rep(i,1,n){
        int k=qread();
        rep(j,1,k){
            int x=qread(),v=qread();
            vec[x].pbI(mp(i,v));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    rep(i,1,n)dis[i][i]=0;
    rep(i,1,m){
        for(auto x:vec[i]){
            for(auto y:vec[i]){
                chmi(dis[x.fi][y.fi],x.se+y.se);
            }
        }
        //\sum k*d<=2e7  x.se,y.se<=2e9 no overflow
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)chmi(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u=qread(),v=qread();
        ll ans=1e18;
        for(auto x:vec[u]){
            for(auto y:vec[v]){
                chmi(ans,x.se+y.se+dis[x.fi][y.fi]);
            }
        }
        ans+=w[u]+w[v];
        printf("%lld\n",ans);
    }
}
/*
promi x!=y
T2 should double check floyd
enum the middle k
promi when k enumed,all shortest path id<=k got
like rg dp
*/