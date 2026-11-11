#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using i64=long long;
const int N=5e2+11,M=5e5+11,D=25;
const i64 INF=1e18;
int tid,n,m,d,q;
int ln[M][D],tm[M][D],pln[M],w[M];
i64 dis[N][N];
void chkmin(i64 &x,i64 y) { x=std::min(x,y); }
int main() {
    cin>>tid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        int k; cin>>k;
        while(k--) {
            int x,t; cin>>x>>t;
            ln[x][++pln[x]]=i;
            tm[x][pln[x]]=t;
        }
    }   
    for(int i=1;i<=n;i++)
        std::fill(dis[i]+1,dis[i]+n+1,INF),dis[i][i]=0;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<pln[i];j++)
            for(int k=j+1;k<=pln[i];k++) {
                i64 v=tm[i][j]+tm[i][k];
                chkmin(dis[ln[i][j]][ln[i][k]],v);
                chkmin(dis[ln[i][k]][ln[i][j]],v);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--) {
        int x,y; cin>>x>>y;
        i64 rs=INF;
        for(int i=1;i<=pln[x];i++)
            for(int j=1;j<=pln[y];j++)
                chkmin(rs,tm[x][i]+tm[y][j]+dis[ln[x][i]][ln[y][j]]);
        cout<<(rs+w[x]+w[y])<<'\n';
    }
    return 0;
}