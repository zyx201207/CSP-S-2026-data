#include<bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define mp mack_pair
#define pb emplace_back
using namespace std;
namespace IO{
    inline int r(){
        int x=1,y=0;
        char c=getchar();
        while(c<'0'||c>'9'){
            if(c=='-')x=-1;c=getchar();
        }
        while(c>='0'&&c<='9'){
            y=(y<<1)+(y<<3)+(c^48);c=getchar();
        }
        return x*y;
    }
    inline void wi(int x){
        if(!x)return;
        if(x<0){putchar('-');x=-x;}
        wi(x/10);putchar(48^(x%10));
    }
    inline void ww(int x){if(!x)putchar('0');else wi(x);putchar(' ');}
    inline void wln(int x){if(!x)putchar('0');else wi(x);putchar('\n');}
    inline void w(int x){if(!x)putchar('0');else wi(x);}
}
using namespace IO;
const int N=40010,inf=1e9;
namespace D1n0{
    int n,k,u[N],v[N],del,dep[N],p,f[N],m[N],c[N];
    vector<pii>ve[N];
    inline void dfs1(int x,int fa){
        dep[x]=dep[fa]+1;f[x]=fa;
        if(dep[x]>dep[p])p=x;
        for(auto i:ve[x])if(i.se!=del&&i.fi!=fa)dfs1(i.fi,x);
    }
    inline int getmid(int x){
        p=0;
        dfs1(x,0);
        int p1=p;p=0;
        dfs1(p1,0);
        int p2=p;
        int d=dep[p2];
        for(int i=1;i<=d/2;++i)p2=f[p2];
        return p2;
    }
    inline void dfs2(int x,int fa){
        int cnt=0;
        m[x]=1;
        for(auto i:ve[x])if(i.se!=del&&i.fi!=fa){
            dfs2(i.fi,x);
            m[x]=max(m[x],m[i.fi]+1);
            ++cnt;
        }
        if(!fa)m[x]=n+1;
        ++c[m[x]];
    }
    inline int solve(int x){
        del=x;
        int a=getmid(u[x]),b=getmid(v[x]);
        for(int i=0;i<=n+1;++i)c[i]=0;
        dfs2(a,0),dfs2(b,0);
        for(int i=0,sum=0;i<=n;++i){
            sum+=c[i];
            if(sum>=n-k)return i;
        }
        return inf;
    }
    inline void solve(){
        n=r();k=r();
        for(int i=1;i<=n;++i)vector<pii>().swap(ve[i]);
        for(int i=1;i<n;++i){
            u[i]=r(),v[i]=r();
            ve[u[i]].pb(v[i],i);
            ve[v[i]].pb(u[i],i);
        }
        int ans=inf;
        for(int i=1;i<n;++i)ans=min(ans,solve(i));
        wln(ans);
    }
    inline void _(){
        int c=r(),t=r();
        while(t--)solve();
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    D1n0::_();
}
/*
g++ hub.cpp -o hub -O2 -std=c++14
*/