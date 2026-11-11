#include <bits/stdc++.h>
using namespace std;
#define int long long
int read () {
    int s=0,f=1;
    char c=getchar();
    while ((c<'0'||c>'9')&&c!='-') c=getchar();
    if (c=='-') {
        f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9') {
        s=s*10+(c-'0');
        c=getchar();
    }
    return s*f;
}
int N=1e17+1;
int c,n,m,d,q;
int w[500001];
int ma[501][501];
struct node {
    int id,v;
};
vector <node> sta[500001];
void init () {
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            ma[i][j]=N;
        }
    }
    for (int i=1;i<=m;i++) {
        w[i]=read();
    }
    int k,a,t;
    for (int i=1;i<=n;i++) {
        k=read();
        ma[i][i]=0;
        for (int j=1;j<=k;j++) {
            a=read();
            t=read();
            if (sta[a].size()!=0) {
                for (int l=0;l<sta[a].size();l++) {
                    ma[i][sta[a][l].id]=min(ma[i][sta[a][l].id],t+sta[a][l].v);
                    ma[sta[a][l].id][i]=min(ma[sta[a][l].id][i],t+sta[a][l].v);
                }
            }
            sta[a].push_back({i,t});
        }
    }
}
void floid () {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
            }
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=n;j++) {
    //         cout<<ma[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}
void work () {
    int x,y,res;
    for (int i=1;i<=q;i++) {
        x=read();
        y=read();
        res=N;
        for (int j=0;j<sta[x].size();j++) {
            for (int k=0;k<sta[y].size();k++) {
                res=min(res,ma[sta[x][j].id][sta[y][k].id]+sta[x][j].v+sta[y][k].v);
            }
        }
        res+=w[x]+w[y];
        cout<<res<<'\n';
    }
}
signed main () {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    init();
    floid();
    work();
    return 0;
}