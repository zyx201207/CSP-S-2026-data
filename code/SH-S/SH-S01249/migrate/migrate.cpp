#include<cctype>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
char buf[1048577],*p1,*p2;
#define gc() p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++
void rd(int &x){
    x=0; char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
}
void rdl(LL &x){
    x=0; char c=gc(); bool fl=0;
    while(!isdigit(c)) fl|=c=='-',c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
    if(fl) x=-x;
}
const int N=2e6+9,INF=1e9;
int n; LL D; LL a[N];
namespace Solver{

int n,pre[N],nxt[N]; LL a[N];
int f[N],g[N],wh[N];
LL sg[N];
LL solve(){
    // printf("D %lld: ",D);
    // for(int i=1;i<=n;i++) printf("%lld ",a[i]); puts("");
    nxt[n]=0; for(int i=1,j=1;i<n;i++){
        while(j<n&&a[j+1]-a[i]<=D) j++;
        nxt[i]=j;
    }
    pre[1]=0; for(int i=n,j=n;i^1;i--){
        while(j>1&&a[i]-a[j-1]<=D) j--;
        pre[i]=j;
    }
    LL res=0;
    for(int i=1;i<=n;i++){
        f[i]=0,wh[0]=i,g[i]=sg[i]=1; sg[i-1]=0;
        for(int j=i+1,t=i;j<=n;j++){
            int l=max(pre[j],i);
            f[j]=f[l]+1;
            g[j]=min((LL)INF,sg[wh[f[pre[j]]]]-sg[l-1]);
            if(g[j]==2) res++;
            // printf("%d %d %d %d %d %d\n",i,j,l,wh[f[pre[j]]],f[j],g[j]);
            wh[f[j]]=j,sg[j]=sg[j-1]+g[j];
        }
    }
    return res;
}

}
void solve(){
    rd(n),rdl(D);
    for(int i=1;i<=n;i++) rdl(a[i]);
    LL res=0;
    for(int i=1,j=1;i<=n;i=++j){
        while(j<n&&a[j+1]-a[j]<=D) j++;
        Solver::n=j-i+1;
        for(int k=i;k<=j;k++) Solver::a[k-i+1]=a[k];
        res+=Solver::solve();
    }
    printf("%lld\n",res);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int SJQ,T; rd(SJQ),rd(T);
    while(T--) solve();
    return 0;
}