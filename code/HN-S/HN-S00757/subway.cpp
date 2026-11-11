#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int> 
#define popc __builtin_popcount
#define All(v) (v).begin(),(v).end()
#define lowbit(x) ((x)&(-(x)))
const int inf=1e18;
const int N=5e5+5;
int n,m,f[505][505],d,q;
vector<pii> v[N];
inline int read(){
    int x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)) t|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?-x:x;
}
int w[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _=read();
    n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) v[i].reserve(d);
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int x=read(),y=read();
            v[x].emplace_back(i,y);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int x=0;x<v[i].size();x++){
            for(int y=x+1;y<v[i].size();y++){
                auto a=v[i][x],b=v[i][y];
                f[a.first][b.first]=min(f[a.first][b.first],a.second+b.second);
                f[b.first][a.first]=min(f[b.first][a.first],a.second+b.second);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x=read(),y=read();
        int res=inf;
        for(auto i:v[x]) for(auto j:v[y]) res=min(res,i.second+j.second+f[i.first][j.first]);
        printf("%lld\n",res+w[x]+w[y]);
    }
    return 0;
}
// Oct31==Dec25?