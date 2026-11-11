#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
typedef long long ll;
const ll inf=1e18;

int read() {
    int s=0;
    char c=getchar();
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
    return s;
}

int n,m,d,q;
int a[M];
vector<pair<int,int> > b[M];
ll dis[N][N];

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();
    n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) a[i]=read();
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++) {
        int k=read();
        while(k--) {
            int x=read(),y=read();
            b[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++) {
        for(auto j:b[i]) for(auto k:b[i]) dis[j.first][k.first]=min(dis[j.first][k.first],(ll)j.second+k.second);
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--) {
        int x=read(),y=read();
        ll res=inf;
        for(auto i:b[x]) for(auto j:b[y]) res=min(res,dis[i.first][j.first]+i.second+j.second);
        printf("%lld\n",a[x]+a[y]+res);
    }
    return 0;
}
//14:47