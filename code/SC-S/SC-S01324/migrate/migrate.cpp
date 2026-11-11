#include<bits/stdc++.h>
#define rep(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("migrate.in");
ofstream ouf("migrate.out");
using lint=long long;
static constexpr auto _infl=(lint)(1e18l);
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int c,T;inf>>c>>T;
    while(T--) []{
        int n;lint d;inf>>n>>d;
        vector<lint> a(n);
        for(auto&x:a) inf>>x;
        vector<int> nxt(n);
        auto r=0;
        rep(i,0,n){
            while(r+1<n&&(a[r+1]-a[i])<d+1) ++r;
            nxt[i]=r;
        }
        auto ans=0ll;
        vector<array<array<lint,4>,4>> f(n);
        for(auto&x:f) for(auto&i:x) i.fill(-1);
        auto calc=[&](auto __self,int p,int s,int t){
            const auto ds=min(3,p-s),dt=min(3,p-t);
            if(~f[p][ds][dt]) return f[p][ds][dt];
            s=(s<0?-1:nxt[s]);
            t=(t<0?-1:nxt[t]);
            f[p][ds][dt]=max(s-max(p,t),0);
            if(nxt[p]-1>s-1){
                t=max({s,t,nxt[p]-2});
                s=nxt[p]-1;
            }else t=max({t,s-1,nxt[p]-2});
            return f[p][ds][dt]+=(nxt[p]!=p?__self(__self,nxt[p],s,t):0);
        };
        rep(i,0,n) ans+=calc(calc,i,-1,-1);
        ouf<<ans<<'\n';
    }();
    return 0;
}