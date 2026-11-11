#include<bits/stdc++.h>
#define mid (l+((r-l)>>1))
#define ls (p<<1)
#define rs (ls|1)
#define lt ls,l,mid
#define rt rs,mid+1,r
#define ll long long
#define int long long
using namespace std;
const int N=1e6+5,M=505;
const ll INF=1e18+5;
ll w[N],cnt[N],e[M][M],k[N];

struct node{
    int id,w;
}a[N][23];


inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}



signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            int tmp1=read(),tmp2=read();
            a[tmp1][++cnt[tmp1]]={i,tmp2};
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=INF;
    for(int i=1;i<=n;i++) e[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<cnt[i];j++){
            for(int k=j+1;k<=cnt[i];k++){
                e[a[i][j].id][a[i][k].id]=e[a[i][k].id][a[i][j].id]=min(e[a[i][j].id][a[i][k].id],(ll)a[i][j].w+(ll)a[i][k].w);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<e[i][j]<<" ";
    //     cout<<endl;
    // }
    // floyd();
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--){
        int s=read(),t=read();
        ll ans=INF;
        for(int i=1;i<=cnt[s];i++){
            for(int j=1;j<=cnt[t];j++) ans=min(ans,e[a[s][i].id][a[t][j].id]+(ll)a[s][i].w+(ll)a[t][j].w);
        }
        printf("%lld\n",ans+w[s]+w[t]);
    }
    return 0;
}