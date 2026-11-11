#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repa(i,a,b) for(int i=(a);i<(b);++i)
#define pr(x) cout<<__LINE__ << #x << x<<endl
#define P 998244353
// #define P 1000000007
#define maxn 2000005
int l[maxn];
LL a[maxn];
// struct node {
//     int ls,rs;
//     int l,r;
//     int v,tag;
// };
// node tr[maxn*4];
// int nodes;
// void down(int p){

// }
// void up(int p){
    
// }
// void build(int l,int r,int p=1){
//     node &now=tr[p];
//     now.l=l;now.r=r;
//     if(l==r){
//         now.ls=now.rs=0;
//         now.v=now.tag=0;//TODO
//         return;
//     }
//     int mid=l+r>>1;
//     now.ls=++nodes;
//     build(l,mid,nodes);
//     now.rs=++nodes;
//     build(mid+1,r,nodes);
//     up(p);
// }
// void update(int l,int r,int v,int p=1){
//     node &now=tr[p];
//     if(now.l>r||now.r<l)return;
//     if(l<=now.l&&now.r<=r){
//         //TODO
//         return;
//     }
//     down(p);
//     update(l,r,v,now.l);
//     update(l,r,v,now.r);
//     up(p);
// }
// int query(int l,int r,int p=1){//TODO
//     node &now=tr[p];
//     if(now.l>r||now.r<l)return 0;//TODO
//     if(l<=now.l&&now.r<=r){
//         //TODO
//         return;
//     }
//     down(p);
//     return query(l,r,now.l)+query(l,r,now.r);//TODO
// }
namespace s40{
const int N=5005;
int dp[N][N],sum[N][N];
int b[N];
void main(){
    int T;cin>>T;
    while(T--){
        int n;LL d;
        cin>>n>>d;
        rep(i,1,n)cin>>a[i];
        int now=1;
        rep(i,1,n){
            while(a[i]-a[now]>d)now++;
            l[i]=now;
        }
        LL ans=0;
        rep(i,1,n){
            repa(j,1,i){
                if(l[i]>=b[j])b[j]=i;
                dp[i][j]=dp[b[j]-1][j]-dp[l[i]-1][j];
                if(dp[i][j]==2)ans++;
                if(dp[i][j]>2)dp[i][j]=3;
                dp[i][j]+=dp[i-1][j];
            }
            dp[i][i]=1;
            b[i]=i+1;
        }
        cout<<ans<<endl;
    }
}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int C,T;cin>>C;
    if(C<=10){
        s40::main();
        return 0;
    }
    // cin>>T;
    // while(T--){
    //     int n;LL d;
    //     cin>>n>>d;
    //     rep(i,1,n)cin>>a[i];
    //     int now=1;
    //     rep(i,1,n){
    //         while(a[i]-a[now]>d)now++;
    //         l[i]=now;
    //     }
    //     LL ans=0;
    //     rep(i,1,n){
    //         ans+=query(1,i-1);
    //         update(1,i,l[i]);
    //     }
    //     cout<<ans<<endl;
    // }
}