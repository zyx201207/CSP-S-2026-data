#include<bits/stdc++.h>
using namespace std;

bool bg_M;
template<typename T>
void read(T &a){
    char c;a=0;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
typedef long long ll;
namespace ZZOI{
int c,n,m,d,q;
const int MAXM=600010,MAXN=610;
const ll INF=1e17;
ll w[MAXM];
vector<pair<int,int>> a[MAXM];// station
vector<pair<int,int>> t[MAXN];// lane
ll dis[MAXN][MAXN];
void main(){
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;++i)read(w[i]);
    for(int i=1;i<=n;++i){
        int k;read(k);
        t[i].resize(k);
        for(int j=0;j<k;++j)read(t[i][j].first),read(t[i][j].second),a[t[i][j].first].emplace_back(i,t[i][j].second);
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=i==j?0:INF;
    for(int i=1;i<=m;++i){
        assert(a[i].size()<=d);
        for(int j=0;j<a[i].size();++j)
            for(int k=j+1;k<a[i].size();++k){
                int x=a[i][j].first,y=a[i][k].first;
                dis[x][y]=min(dis[x][y],(ll)a[i][j].second+a[i][k].second);
                dis[y][x]=min(dis[y][x],(ll)a[i][j].second+a[i][k].second);
            }
    }
    // for(int i=1;i<=n;++i,puts(""))for(int j=1;j<=n;++j)printf("%lld ",dis[i][j]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)   
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    // for(int i=1;i<=n;++i,puts(""))for(int j=1;j<=n;++j)printf("%lld ",dis[i][j]);
    int x,y;
    while(q--){
        read(x),read(y);
        ll ans=INF;
        for(int i=0;i<a[x].size();++i)
            for(int j=0;j<a[y].size();++j){
                int c=a[x][i].first,d=a[y][j].first;
                if(dis[c][d]==INF)continue;
                ans=min(ans,dis[c][d]+a[x][i].second+a[y][j].second);
            }
        write(ans+w[x]+w[y]);puts("");
    }
}
}
bool ed_M;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)ZZOI::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&bg_M)/1024.0/1024<<" Mb"<<endl;
    return 0;
}