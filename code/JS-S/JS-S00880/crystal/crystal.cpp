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
#define inf 1000000000
#define MOD 1000000007//998244353
#define MAXN 500010
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
int n,k,a[MAXN];
bool FLB;
signed main(){
    cerr<<((&FLB)-(&FLA))/1024.0/1024<<endl;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    rep(i,1,n)a[i]=qread();
    sort(a+1,a+1+n);
    int p=1,ans=0;
    rep(i,1,n){
        while(k<0){k+=a[i]-a[p];p++;}
        ans=max(ans,i-p+1);
        k-=(i-p+1)*(a[i+1]-a[i]);//5e5*2e12=1e18
    }
    cout<<ans;
}
/*
T3:
ex u,v jmp rg ?
*/