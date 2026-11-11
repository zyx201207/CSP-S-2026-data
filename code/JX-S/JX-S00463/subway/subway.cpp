#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__);
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=505,M=5e5+5;
ll f[N][N],w[M];
typedef pair<int,ll> pii;
vector<pii> vec[M];
template<typename T>
void chkmin(T&x,T y){
    x=min(x,y);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scan>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scan>>w[i];
    for(int i=1;i<=n;i++){
        int cnt;
        scan>>cnt;
        for(int j=1,x,w;j<=cnt;j++){
            scan>>x>>w;
            vec[x].emplace_back(i,w);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto u:vec[i]){
            for(auto v:vec[i]){
                chkmin(f[u.first][v.first],u.second+v.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scan>>x>>y;
        ll res=inf;
        for(auto u:vec[x]){
            for(auto v:vec[y]){
                res=min(res,u.second+v.second+f[u.first][v.first]);
            }
        }
        printf("%lld\n",res+w[x]+w[y]);
    }
    return 0;
}