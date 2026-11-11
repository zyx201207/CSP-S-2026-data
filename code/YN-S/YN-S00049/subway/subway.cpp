#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5,M=5e5+5;
const ll INF=1e18;
int cas,n,m,d,q,w[M];ll dis[N][N];
struct node{int id,t;};
vector<node>sta[M];
#define pb push_back
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x)
inline int rd(){int x=0;char c=gc();for(;!isdigit(c);c=gc());for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);return x;}
inline void wt(ll x){char s[20];int t=0;while(x)s[++t]=x%10+48,x/=10;while(t)pc(s[t--]);}//没有0的情况
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    cas=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++)w[i]=rd();
    for(int i=1,k;i<=n;i++){
        k=rd();
        for(int a,t;k;k--)a=rd(),t=rd(),sta[a].pb({i,t});
        for(int j=1;j<=n;j++)dis[i][j]=INF;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int jj=0;jj<sta[i].size();jj++){
            int j=sta[i][jj].id,t1=sta[i][jj].t;
            for(int kk=0;kk<jj;kk++){
                int k=sta[i][kk].id,t2=sta[i][kk].t;
                dis[j][k]=dis[k][j]=min(dis[j][k],(ll)t1+t2);
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int x,y;q;q--){
        x=rd(),y=rd();ll ans=INF;
        for(auto[i,t1]:sta[x])for(auto[j,t2]:sta[y])ans=min(ans,dis[i][j]+t1+t2);
       wt(ans+w[x]+w[y]),pc('\n');
    }
}
//地铁口肯定只会走一次，先加上
//将站台和站厅拆开
//考虑先走哪个线路->O(n)
//一个线路到另外一个线路：站台->站厅->站台
//复杂度(d^2q)可过
