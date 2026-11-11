#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repa(i,a,b) for(int i=(a);i<(b);++i)
#define pr(x) cout<<__LINE__ << #x << x<<endl
#define P 998244353
// #define P 1000000007
#define maxn 505
#define maxm 500005
int w[maxm];
vector<int>b[maxm],c[maxm];
LL a[maxn][maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int C,n,m,d,Q;cin>>C>>n>>m>>d>>Q;
    rep(i,1,m){
        cin>>w[i];
    }
    rep(i,1,n){
        int cnt;cin>>cnt;
        rep(j,1,cnt){
            int x,y;cin>>x>>y;
            b[x].push_back(i);
            c[x].push_back(y);
        }
    }
    rep(i,1,n)rep(j,1,n)a[i][j]=1000000000000000LL;
    rep(i,1,n)a[i][i]=0;
    rep(i,1,m){
        repa(j,0,b[i].size()){
            repa(k,j+1,b[i].size()){
                int x=b[i][j],y=b[i][k];
                if(a[x][y]>c[i][j]+c[i][k])a[x][y]=a[y][x]=c[i][j]+c[i][k];
            }
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(Q--){
        int x,y;cin>>x>>y;
        LL ans=1000000000000000LL;
        repa(i,0,b[x].size()){
            repa(j,0,b[y].size()){
                // pr(b[x][i]);pr(b[y][j]);
                // pr(w[x]);pr(w[y]);
                // pr(c[x][i]);pr(c[y][j]);
                // pr(a[b[x][i]][b[y][j]]);
                ans=min(ans,a[b[x][i]][b[y][j]]+w[x]+w[y]+c[x][i]+c[y][j]);
            }
        }
        cout<<ans<<endl;
    }
}