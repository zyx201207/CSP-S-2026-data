#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500,M=5e5;
ll f[N+5][N+5],ans;
int c,n,m,d,Q,w[M+5];
vector<pair<int,int>> g[M+5];
inline int read() {
    char ch=getchar();
    int x=0;
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
inline void write(ll x) {
    if(x>9) write(x/10);
    putchar((x%10)+'0');
    return ;
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),Q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1,k,x,t;i<=n;i++) {
        k=read();
        for(int j=1;j<=k;j++) {
            x=read(),t=read();
            g[x].push_back({i,t});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1,len;i<=m;i++) {
        sort(g[i].begin(),g[i].end());
        len=g[i].size();
        for(int p=0,u,w1;p<len-1;p++) {
            u=g[i][p].first,w1=g[i][p].second;
            for(int q=p+1,v,w2;q<len;q++) {
                v=g[i][q].first,w2=g[i][q].second;
                f[u][v]=min(f[u][v],(ll)(w1+w2));
            }
        }
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(k==i||k==j) continue;
                if(k<i) f[i][j]=min(f[i][j],f[k][i]+f[k][j]);
                else if(k>j) f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
                else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(Q--) {
        int x,y,lenx,leny;
        x=read(),y=read();
        lenx=g[x].size(),leny=g[y].size();
        ans=2e18;
        for(int i=0,u,w1;i<lenx;i++) {
            u=g[x][i].first,w1=g[x][i].second;
            for(int j=0,v,w2;j<leny;j++) {
                v=g[y][j].first,w2=g[y][j].second;
                if(u<v) ans=min(ans,f[u][v]+(ll)(w1+w2));
                else ans=min(ans,f[v][u]+(ll)(w1+w2));
            }
        }
        ans+=(ll)(w[x]+w[y]);
        write(ans),putchar('\n');
    }
    return 0;
}
