#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define inf (int)(1e18)
using namespace std;
inline int rd(){
    int x=0,f=0;char c=getchar();
    while(!isdigit(c)) f=(c=='-'),c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?-x:x;
}
const int N=2e6+10;
int f[N][3],r[N],n,a[N],d;
void solve(){
    n=rd();d=rd();
    For(i,1,n) a[i]=rd();
    r[0]=1;
    For(i,1,n){
        r[i]=r[i-1];
        while(r[i]<n&&(a[r[i]+1]-a[i])<=d) r[i]++;
        For(j,0,2) f[i][j]=0;
    }
    // 0 对应 x 1 1
    // 1 对映 x 1
    // 2 对应 x 2
    for(int i=n;i>=1;i--){
        if(i!=1){
            int p1=r[i-2],p2=r[i-1],p3=r[i];
            int tp=-1;
            if((p3-p2)>=2) tp=0;
            else if((p3-p2)==1) tp=1;
            else if(p2>p1) tp=2;
            if(tp!=-1) f[i][0]=f[p3][tp]+(p2-p1);
        }
        int p1=r[i-1],p2=r[i];
        int tp=-1;
        if((p2-p1)>=2) tp=0;
        else if((p2-p1)==1) tp=1;
        if(tp!=-1) f[i][1]=f[p2][tp];
        if((p2-p1)>0) f[i][2]=f[p2][2]+(p2-p1);
    }
    int ans=0;
    For(i,1,n){
        if(r[i]==(i+1)) ans+=f[r[i]][1];
        if(r[i]>(i+1)) ans+=f[r[i]][0];
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=rd(),T=rd();
    while(T--) solve();
}