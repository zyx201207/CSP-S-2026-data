#include<bits/extc++.h>
using namespace std;
using ll=long long;
const int N=510,M=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n,m,d,q;
int w[M],k[M];
int a[N][M],t[N][M];

void Solve9(){
    vector<vector<ll>> dis(m+5,vector<ll>(m+5,0));
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=n;++i){
        for(int u=1;u<=k[i];++u){
            for(int v=1;v<=k[i];++v){
                int x=a[i][u],y=a[i][v];
                if(x==y) dis[x][y]=0;
                else dis[x][y]=t[i][u]+t[i][v];
            }
        }
    }
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int st,ed; cin>>st>>ed;
        cout<<(w[st]+dis[st][ed]+w[ed])<<"\n";
    }
}

int main(){
    auto ___=freopen("subway.in","r",stdin);
    auto _=freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c; cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[i][j];
    }

    Solve9();
    
    return 0;
}

// g++ subway.cpp -O2 -std=c++14 -static -o test.exe
// ./test.exe < subway.in > test.out
// diff test.out subway.ans