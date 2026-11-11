#include <bits/stdc++.h>
using namespace std;

#define int long long

int to[1000011][2],r[1000011],h[500011],w[500011],f[511][511],c,n,m,d,q,tot;

inline void read(int &x){
    char c=getchar();
    int s=1;
    while(c<'0'||c>'9'){
        if(c=='-')
            s*=-1;
        c=getchar();
    }
    x=0;
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-48,
        c=getchar();
    x*=s;
    return;
}

inline void push(int u,int v,int w){
    to[++tot][0]=v,to[tot][1]=w;
    r[tot]=h[u],h[u]=tot;
    return;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;i++)
        read(w[i]);
    for(int i=1;i<=n;i++){
        int k;
        read(k);
        for(int j=1;j<=k;j++){
            int a,t;
            read(a),read(t);
            push(a,m+i,t);
            push(m+i,a,t);
        }
    }
    memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int i=m+1;i<=n+m;i++)
        for(int j=h[i];j;j=r[j])
            for(int k=h[to[j][0]];k;k=r[k])
                f[i-m][to[k][0]-m]=min(f[i-m][to[k][0]-m],to[j][1]+to[k][1]),
                f[to[k][0]-m][i-m]=min(f[to[k][0]-m][i-m],to[j][1]+to[k][1]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(f[i][k]<(1ll<<60)&&f[k][j]<(1ll<<60))
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(;q--;){
        int x,y,ans=1ll<<60;
        read(x),read(y);
        for(int i=h[x];i;i=r[i])
            for(int j=h[y];j;j=r[j])
                if(f[to[i][0]-m][to[j][0]-m]<(1ll<<60))
                    ans=min(ans,f[to[i][0]-m][to[j][0]-m]+to[i][1]+to[j][1]);
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
