#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define de(x...) fprintf(stderr,x)
#define rep(i,l,r) for(auto i = l;i <= r;++i)
#define per(i,l,r) for(auto i = l;i >= r;--i)
#define eb emplace_back
const int N = 505,M = 500005,P = 22;
const ll I = 1e18;
int Tid,n,m,K[M],D,T,W[M];
ll f[N][N];
vector<int> a[N],t[N];
struct node{
    int i,x;
};
vector<node> has[M];
inline int read(){
    int x = 0;
    char c = getchar();
    while((c ^ 48) > 9) c = getchar();
    while((c ^ 48) <= 9)    x = (x<<3) + (x<<1) + (c ^ 48),c = getchar();
    return x;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Tid = read(),n = read(),m = read(),D = read(),T = read();
    rep(i,1,m)  W[i] = read();
    rep(i,1,n){
        K[i] = read(),a[i].resize(K[i]),t[i].resize(K[i]);
        rep(j,0,K[i]-1) a[i][j] = read(),t[i][j] = read(),has[a[i][j]].eb((node){i,j});
    }
    rep(i,1,n)
        rep(j,1,n)  f[i][j] = I * (i != j);
    rep(i,1,n)
        rep(j,0,K[i]-1)
            for(auto [k,x]:has[a[i][j]]){
                if(i == k)  continue;
                f[i][k] = min(f[i][k],(ll)t[i][j] + t[k][x]);
            }
    rep(k,1,n)
        rep(i,1,n)
            rep(j,1,n)  f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    // rep(i,1,n)
        // rep(j,i+1,n)  de("f[%d][%d] = %lld\n",i,j,f[i][j]);
    rep(tt,1,T){
        int x,y;
        x = read(),y = read();
        ll A = I;
        for(auto [X,i]:has[x])
            for(auto [Y,j]:has[y])  A = min(A,f[X][Y] + t[X][i] + t[Y][j]);
        A += W[x] + W[y];
        printf("%lld\n",A);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}