// #define DEBUG
#include<bits/stdc++.h>
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#ifdef DEBUG
#define fin cin
#define fout cout
#endif
using i64=long long;
using f64=double;
using pii=pair<int,int>;
using vci=vector<int,int>;
#define pbk push_back
#define ctn continue
#define rtn return
#define brk break
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define re(i,a) for(int i=1;i<=(a);++i)
#define rel(i,a) for(int i=0;i<(a);++i)
#define chmn(a,b) a=min((a),(b))
#define chmx(a,b) a=max((a),(b))
/*--------------------------------------------------------*/
int xieyuhang_lixinyuan;
i64 x[2000010];
int nxt[2000010];
int prv[5010];
int ya8[5010];
int dis[5010];
void solve1(){
    i64 d;int n;fin>>n>>d;
    re(i,n)fin>>x[i];
    re(i,n)nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1,prv[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
    i64 ans=0;
    re(s,n){
        memset(ya8,0,sizeof(ya8));
        memset(dis,0,sizeof(dis));
        ya8[s]=1;int r=s;
        rep(t,s+1,n){
            int l=max(prv[t],s);
            dis[t]=dis[l]+1;
            if(dis[t]>dis[t-1])r=t-1;
            if(l>r)ctn;
            if(l<r-1){ya8[l]=3;ctn;}
            if(l==r-1)ya8[t]=ya8[l]+ya8[r];
            else ya8[t]=ya8[l];
            if(ya8[t]==2)ans++;
        }
    }fout<<ans<<"\n";
}void solve2(){
    i64 d;int n;fin>>n>>d;
    re(i,n)fin>>x[i];
    i64 a=x[2]-x[1];
    if(d/a<=1)fout<<0<<"\n";
    else fout<<max(n-d/a-d/a+1,0LL)<<"\n";
}void solve3(){
    i64 d;int n;fin>>n>>d;
    re(i,n)fin>>x[i];
    re(i,n)nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1,prv[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
    i64 ans=0;
    re(i,n){
        if(prv[i]>=i-1)ctn;
        ans+=nxt[i-1]-nxt[i-2];
    }fout<<ans<<"\n";
}
int main(){
    int T;fin>>xieyuhang_lixinyuan>>T;
    while(T--){
        if(xieyuhang_lixinyuan<=10)solve1();
        else if(xieyuhang_lixinyuan<=12)solve2();
        else solve3();
    }
}
