#include <bits/stdc++.h>
using namespace std;
namespace LUCKY{

using ll = long long;
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using PII = pair<int,int>;
#define fi first
#define se second

constexpr int N=2e6+6;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

int c,T,n,d;
int a[N];

// int checkk(int x){
//     return lower_bound(a+1,a+1+n,a[x]-d)-a;
// }

// bool check(int x){
//     if(x==1) return false;
//     int it1=checkk(x);
//     if(it1>=x-1) return false;
//     int it2=it1+1;
//     int it3=checkk(it2);
//     if(it3!=it1) return true;
//     return false;
// }

vector<int> G[N];
int dis[N],f[N],g[N];
bool vis[N];
queue<int> Q;

int run(int l,int r){
    // cerr<<"run: "<<l<<' '<<r<<endl;
    // cerr<<"a: ";
    // For(i,l,r) cerr<<a[i]<<' ';;cerr<<endl;
    // For(i,l,r) f[i]=0;; f[l]=1;
    // int p=l,sum=1,res=0;
    // For(i,l+1,r){
    //     while(a[i]-a[p]>d)
    //         sum-=f[p],++p;
    //     f[i]=sum; sum+=f[i];
    //     cerr<<i<<' '<<p<<' '<<d<<endl;
    //     res+=(sum==2);
    // } cerr<<"f: ";
    // For(i,l,r) cerr<<f[i]<<' ';;cerr<<endl;
    // return sum;
    For(i,l,r) G[i].clear();
    For(i,l,r) dis[i]=INF;
    For(i,l,r){
        For(j,i+1,r){
            if(a[j]-a[i]>d) break;
            G[i].push_back(j);
        }
    } Q.push(l);
    For(i,l,r) f[i]=INF,g[i]=0,vis[i]=false;
    f[l]=0,g[l]=1;
    while(Q.size()){
        int u=Q.front(); Q.pop();
        for(int v:G[u]){
            if(f[v]==f[u]+1)
                g[v]+=g[u]; // ,cerr<<v<<' '<<u<<endl;
            else if(f[v]>f[u]+1)
                f[v]=f[u]+1,g[v]=g[u];
            if(!vis[v])
                Q.push(v),vis[v]=true;
        }
    } int res=0;
    // cerr<<"debug: "<<endl;
    // For(i,l,r) cerr<<i<<' '<<f[i]<<' '<<g[i]<<endl;
    For(i,l,r) res+=(g[i]==2);
    return res;
}

void OvO(){
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        For(i,1,n) cin>>a[i];
        // sort(a+1,a+1+n);
        if(n==1){
            cout<<0<<endl;
        } else if(c>=11&&c<=12){
            int delta=a[2]-a[1];
            int m=d/delta;
            if(m<=1) cout<<0<<endl;
            else cout<<max(n-(2*m-1),0ll)<<endl;
        } else if(c<=6){
            vector<int> p;
            p.reserve(n+1);
            p.emplace_back(0);
            For(i,1,n-1){
                if(a[i+1]-a[i]>d)
                    p.emplace_back(i);
            } p.emplace_back(n);
            int ans=0;
            For(i,0,(int)p.size()-2){
                For(j,p[i]+1,p[i+1])
                    ans+=run(j,p[i+1]);
            } cout<<ans<<endl;
        } else{
            cout<<0<<endl;
        }
        // For(i,1,n-4){
        // }
    }
}

#undef int
} using LUCKY::OvO;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	OvO(); return 0;
}

/*

g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall -Wextra -static

*/