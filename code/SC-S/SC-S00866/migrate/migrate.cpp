#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef long long ll;

const int N=2e6+10;

int c,T;
int n;
ll d;
ll x[N];
int tol[N],tor[N];
ll cc[N],dd[N],ee[N],ff[N];

ll read(){
    char c=getchar();
    ll x=0,y=0;
    while(c<'0'||c>'9') y=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return y?-x:x;
}
void work(){
    n=read(),d=read();
    for(int i=1;i<=n;++i) x[i]=read();
    for(int i=1;i<=n;++i) cc[i]=0;
    for(int i=1;i<=n;++i) dd[i]=0;
    for(int i=1;i<=n;++i) ee[i]=0;
    for(int i=1;i<=n;++i) ff[i]=0;
    for(int r=1,l=1;r<=n;++r){
        while(x[r]-x[l]>d) ++l;
        tol[r]=l;
    }
    for(int l=1,r=1;l<=n;++l){
        while(r<n&&x[r+1]-x[l]<=d) ++r;
        tor[l]=r;
        // printf("%lld %d %d\n",x[l],tol[l],tor[l]);
    }
    for(int i=n;i;--i) (tol[i]<i?ff[tol[i]]+=(tor[tol[i]]==i?ff[i]:0)+1:0);
    for(int i=n;i;--i) if(tol[i]+1<i) cc[tol[i]+1]+=(tor[tol[i]+1]==i?ff[i]:0)+1;
    for(int i=1;i<=n;++i) if(tor[i]>i+1) ee[tor[i]]+=(i>1&&x[tor[i]]-x[i-1]>d?ee[i]+1:1);else if(tor[i]>i) ee[tor[i]]+=(tol[tor[i]]==i?ee[i]:0)+1;
    for(int i=1;i<=n;++i) if(tor[i]>i+1) dd[tor[i]]+=(i>1&&x[tor[i]-1]-x[i-1]>d?ee[i]+1:1)/*,printf("-- %d %d %d\n",i,tor[i],dd[tor[i]])*/;else if(tor[i]>i) dd[tor[i]]+=(tol[tor[i]]==i?ee[i]:0)+1;//,printf("--- %d %d %d\n",i,tor[i],dd[tor[i]]);
    ll res=0;
    for(int i=1;i<=n;++i) res+=(ll)cc[i]*dd[i];//,printf("%d %lld %lld %lld %lld\n",i,cc[i],dd[i],ee[i],ff[i]);
    printf("%lld\n",res);
}
int main(){
    Fre("migrate");

    c=read(),T=read();
    while(T--) work();

    return 0;
}