/*
宇宙冷漠，这张牌我是，非常了解的。
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int Type;
int n;
ll d;
const int N=2e6;
ll a[N+5];
template<typename T>
void read(T &x){
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    if(f) x=-x;
}
void write(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
int L[N+5],R[N+5];
int LL[N+5],RR[N+5],pre[N+5],suf[N+5],gll[N+5],glr[N+5],grl[N+5],grr[N+5];
void solve(){
    read(n),read(d);
    for(int i=1;i<=n;++i) read(a[i]);
    int p=1;
    for(int i=1;i<=n;++i){
        while(a[i]-a[p]>d) ++p;
        L[i]=p;
        LL[i]=RR[i]=0;
        gll[i]=n+1;
        glr[i]=0;
        grl[i]=n+1;
        grr[i]=0;
    }
    p=n;
    for(int i=n;i>=1;--i){
        while(a[p]-a[i]>d) --p;
        R[i]=p;
    }
    for(int i=1;i<=n;++i){
        if(R[L[i]]==i){
            LL[i]=L[i];
            RR[L[i]]=i;
        }
        gll[R[i]]=min(gll[R[i]],i);
        glr[R[i]]=i;
        grl[L[i]]=min(grl[L[i]],i);
        grr[L[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(LL[i]==0) pre[i]=0;
        else pre[i]=pre[LL[i]]+max(glr[i]-gll[i]+1,0);
    }
    for(int i=n;i>=1;--i){
        if(RR[i]==0) suf[i]=0;
        else suf[i]=suf[RR[i]]+max(grr[i]-grl[i]+1,0);
    }
    long long ans=0;
    for(int i=2;i<=n-2;++i){
        if(L[R[i+1]]==i&&R[L[i]]==i+1){
            ans+=(ll)pre[L[i]]*suf[R[i+1]];
        }
        if(L[R[i+1]]==i){
            int tmpl=max(L[i],gll[i+1]),tmpr=min(i-1,glr[i+1]);
            ans+=(ll)max(tmpr-tmpl+1,0)*suf[R[i+1]];
        }
        if(R[L[i]]==i+1){
            int tmpl=max(i+2,grl[i]),tmpr=min(R[i+1],grr[i]);
            ans+=(ll)pre[L[i]]*max(tmpr-tmpl+1,0);
        }
        int tmpll=max(L[i],gll[i+1]),tmplr=min(i-1,glr[i+1]);
        int tmprl=max(i+2,grl[i]),tmprr=min(R[i+1],grr[i]);
        ans+=(ll)max(tmplr-tmpll+1,0)*max(tmprr-tmprl+1,0);
    }
    write(ans);
    putchar('\n');
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int Tcases=1;
    read(Type);
    read(Tcases);
    while(Tcases--) solve();
    return 0;
}
/*
在古代，穷人一拳打倒十个保安到底有多爽。

16:42 T3

真好，1h 就打完了，最好有暴力对拍

蒋介龟有世界上最大的石头
蒋介龟有世界上最大的石头
蒋介龟有世界上最大的石头
蒋介龟有世界上最大的石头
蒋介龟有世界上最大的石头
蒋介龟有世界上最大的石头

*/