#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
#define inf 1000000000000000000
#define MOD 1000000007//998244353
#define MAXN 2000010
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
int n,d,x[MAXN];
int to1[MAXN],to2[MAXN];
int dp[MAXN][3];
void solve(){
    n=qread(),d=qread();
    rep(i,1,n)x[i]=qread();    
    rep(i,1,n){
        to1[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
        to2[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
    }
    rep(i,1,n){
        int r=to1[i];
        if(r==i)continue;
        dp[r][0]++;if(r!=i+1)dp[r][1]++;
    }
    rep(i,1,n){
        int r=to1[i];
        if(r==i)continue;
        if(to2[r]==i){
            dp[r][0]+=dp[i][0];
            dp[r][2]+=dp[i][2];
        }
        if(to1[i-1]==r&&to2[r]==i-1)dp[r][2]+=dp[i][1];
        if(r!=i+1){
            if(to2[r-1]==i&&to2[r]==i)dp[r][1]+=dp[i][0];
            // if(to2[r-1]==i-1&&to2[r]==i&&to1[i-1]==r-1)dp[r][1]+=dp[i][1];
        }
    }
    ll ans=0;
    rep(i,1,n){
        int l=to2[i];
        if(l==i)continue;
        ans+=(((l+1)!=i)*dp[l+1][1])+dp[l][2];
    }
    printf("%lld\n",ans);
    rep(i,0,n+1)rep(j,0,2)dp[i][j]=0;
    // memset(dp,0,sizeof(dp));
    // memset(to1,0,sizeof(to1));
    // memset(to2,0,sizeof(to2));
    // memset(x,0,sizeof(x));
}
bool FLB;
signed main(){
    cerr<<((&FLB)-(&FLA))/1024.0/1024<<endl;
    // freopen("a.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)solve();
}
/*
like contest before
ex u,v find shortest path
should be of same len
if 2 path same
there should only be one path
else this path should be the only one

in only a range two path may differ

|x_i-x_j|>d
dp[i][0/1/2]=i 
*/