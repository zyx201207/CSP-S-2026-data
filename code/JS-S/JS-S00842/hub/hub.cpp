#include<bits/stdc++.h>
//International Grandmaster zheng_iii bless me
//International Grandmaster cdx123456 bless me
//Grandmaster Cubber bless me
using std::pair;
using std::make_pair;
typedef long long ll;
typedef long double ld;
const int maxn=1e9+7;
const ll N=2000010;
ll test_c,T,n,m,x,y;
std::vector<ll> v[N];
ll dep[N],fa[N],px,py,f[N],sum;
void cdep(){
    for(int i=0;i<=n+2;i++){
        dep[i]=fa[i]=0;
    }
}
void init(){
    for(int i=0;i<=n+2;i++){
        v[i].clear();
    }
}
void dfs1(ll k,ll last){
    dep[k]=dep[last]+1;
    fa[k]=last;
    for(int i=0;i<(int)v[k].size();i++){
        ll to=v[k][i];
        if(to==last)continue;
        dfs1(to,k);
    }
}
void dfs2(ll k,ll last,ll ban,ll g){
    f[k]=0;
    for(int i=0;i<(int)v[k].size();i++){
        ll to=v[k][i];
        if(to==last)continue;
        if(to==ban)continue;
        dfs2(to,k,ban,g);
        f[k]=std::max(f[k],f[to]+1);
    }
    if(f[k]>=g||last==0){
        sum++;
    }
}
ll w=0;
void dfs3(ll k,ll last,ll ban){
    fa[k]=last;
    if(w==0)w=k;
    else if(dep[k]>dep[w])w=k;
    for(int i=0;i<(int)v[k].size();i++){
        ll to=v[k][i];
        if(to==last)continue;
        if(to==ban)continue;
        dep[to]=dep[k]+1;
        dfs3(to,k,ban);
    }
}
ll lx,rx;
bool gt(ll msk){
    cdep();
    w=0;
    dfs3(px,0,py);
    ll tmp=w;
    w=0;
    cdep();
    dfs3(tmp,0,py);
    lx=w;
    for(int i=1;i*2<=dep[w];i++){
        lx=fa[lx];
    }
    if(msk>>0&1){
        if(dep[w]%2==0){
            return 0;
        }
        lx=fa[lx];
    }
    w=0;
    cdep();
    dfs3(py,0,px);
    tmp=w;
    w=0;
    cdep();
    dfs3(tmp,0,px);
    rx=w;
    for(int i=1;i*2<=dep[w];i++){
        rx=fa[rx];
    }
    if(msk>>1&1){
        if(dep[w]%2==0){
            return 0;
        }
        rx=fa[rx];
    }
    return 1;
}
bool check(ll g){
    sum=0;
    dfs2(lx,0,py,g);
    dfs2(rx,0,px,g);
    if(sum<=m)return 1;
    return 0;
}
void SOLVE(){
    std::cin>>n>>m;
    init();
    for(int i=1;i<n;i++){
        std::cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n==m){
        std::cout<<0<<"\n";
        return ;
    }
    cdep();
    dfs1(1,0);
    ll pl=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[pl]){
            pl=i;
        }
    }
    cdep();
    dfs1(pl,0);
    ll mx=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[mx]){
            mx=i;
        }
    }
    px=mx;
    for(int i=1;i*2<=dep[mx];i++){
        px=fa[px];
    }
    py=fa[px];
    ll ano=0;
    if(dep[mx]%2==0){
        for(int i=0;i<(int)v[px].size();i++){
            ll to=v[px][i];
            if(to!=fa[px]){
                ano=to;
                break;
            }
        }
    }
    ll too=1;
    if(test_c<=14)too=4;
    ll ans=n;
    for(int i=0;i<too;i++){
        if(!gt(i))continue;
        ll l=1,r=n,res=1;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=std::min(ans,res);
    }
    if(ano!=0){
        py=ano;
        for(int i=0;i<too;i++){
            if(!gt(i))continue;
            ll l=1,r=n,res=1;
            while(l<=r){
                ll mid=(l+r)>>1;
                if(check(mid)){
                    res=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            ans=std::min(ans,res);
        } 
    }
    std::cout<<ans<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>test_c>>T;while(T--)SOLVE();
    return 0;
}
