#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
#define pushb push_back
using int64=long long;constexpr int64 INF64=0x3f3f3f3f3f3f3f3f;constexpr int INF=0x3f3f3f3f;
constexpr int N=2e6+10;int task_id;using namespace std;
int n,R[N];int64 A[N],d;
namespace solve1{
    bool check(){return n<=300;}
    constexpr int N=300+10;
    int f[N][N],g[N][N];
    void solve(){
        forUp(len,2,n)for(int l=1,r=len;r<=n;++l,++r){
            if(r<=R[l])f[l][r]=g[l][r]=1;
            else{
                f[l][r]=INF;g[l][r]=0;
                for(int k=l+1;k<r&&k<=R[l];++k){
                    if(f[l][k]+f[k][r]<f[l][r])f[l][r]=f[l][k]+f[k][r],g[l][r]=min(3,g[l][k]*g[k][r]);
                    else if(f[l][k]+f[k][r]==f[l][r])g[l][r]=min(3,g[l][r]+g[l][k]*g[k][r]);
                }
            }
        }
        int ans=0;
        forUp(l,1,n)forUp(r,l+1,n)if(g[l][r]==2)++ans;
        cout<<ans<<'\n';
    }
}
void solve(int test_id){
    cin>>n>>d;
    forUp(i,1,n)cin>>A[i];
    int r=1;forUp(l,1,n){
        while(r<n&&A[r+1]-A[l]<=d)++r;
        R[l]=r;
    }
    if(solve1::check())return solve1::solve();
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int test_num=1,tst=clock();
    cin>>task_id;
    cin>>test_num;
    forUp(test_id,1,test_num)solve(test_id);
    cerr<<1000.0*(clock()-tst)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}