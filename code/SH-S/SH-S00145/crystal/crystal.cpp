#include<bits/stdc++.h>
using ll=long long;
char *p1,*p2,buf[100000];
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
template<typename t>
t rd(t&x){
    x=0;
    int c=gc(),f=1;
    while(!isdigit(c)) f=(c=='-'?-1:1),c=gc();
    while(isdigit(c)) x=x*10-'0'+c,c=gc();
    x*=f;
    return x;
}
template<typename t,typename...ts>
void rd(t&x,ts&...y){
    rd(x);rd(y...);
}
template<typename t>
void wt(t x){
    static int st[64],tp;
    tp=0;
    if(!x) return putchar('0'),void();
    if(x<0){
        putchar('-');
        x=-x;
    }
    while(x) st[++tp]=x%10,x/=10;
    while(tp) putchar(st[tp--]+'0');
}
template<>
void wt(char x){putchar(x);}
template<typename t,typename...ts>
void wt(t x,ts...y){
    wt(x);wt(y...);
}
const int maxn=5e5+10;
ll n,m;
ll a[maxn];
ll b[maxn];
ll cst(int l,int r){
    return 1ll*(r-l+1)*a[r]-b[r]+b[l-1];
}
bool chk(int x){
    for(int i=1;i+x-1<=n;i++){
        if(cst(i,i+x-1)<=m) return true;
    }
    return false;
}
int main(){
//	froepen("crystal2.in","r",stdin);
//  freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    rd(n,m);
    for(int i=1;i<=n;i++){
        rd(a[i]);
    }
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    ll l=1,r=n+1;
    while(l<r){
        int mid=(r+l+1)>>1;
        if(chk(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    wt(l);
    return 0;
}
