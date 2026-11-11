#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
long long d;
int x[maxn];
int lst[maxn];
struct tree {
    long long l,r,minn,F;
} t[maxn<<2];
inline void build (int l,int r,int p ) {
    t[p]={l,r,n+1,1};
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(l,mid,p*2);
    build(mid+1,r,p*2+1);
}
inline void pushup (int p) {
    t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
    if(t[p*2].minn == t[p*2+1].minn) {
        t[p].F=t[p*2].F+t[p*2+1].F;
    }
    if(t[p*2].minn > t[p*2+1].minn) t[p].F=t[p*2+1].F;
    if(t[p*2].minn < t[p*2+1].minn) t[p].F=t[p*2].F;
}
inline void update (int x,int p,pair<long long,long long> k) {
    if(t[p].l==t[p].r) {
        t[p].minn=k.first;
        t[p].F=k.second;
        return ;
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(x<=mid) update(x,p*2,k);
    if(x>mid) update(x,p*2+1,k);
    pushup(p);
}
inline pair<long long,long long> query (int l,int r,int p) {
    if(l<=t[p].l && t[p].r<=r) {
        return {t[p].minn,t[p].F};
    }
    int mid=(t[p].l+t[p].r)>>1;
    pair<int,int> L={-1,-1},R={-1,-1},X;
    if(l<=mid) L=query(l,r,p*2);
    if(r>mid) R=query(l,r,p*2+1);
    if(L==pair<int,int> {-1,-1} ) return R;
    if(R==pair<int,int> {-1,-1} ) return L;
    X.first=min(L.first,R.first);
    if(L.first == R.first) X.second=L.second+R.second;
    if(L.first > R.first) X.second=R.second;
    if(L.first < R.first) X.second=L.second;
    return X;
}
inline void solve () {
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=n;++i) {
        int f=i;
        while(f>1 && x[i]-x[f-1]<=d) --f;
        lst[i]=f;
    }
    int res=0;
    for(int l=1;l<=n;++l) {
        for(int r=l;r<=n;++r) {
            build(1,n,1);
            update(l,1,{0,1});
            for(int i=l+1;i<=r;++i) {
                pair<long long,long long> X=query(max(l,lst[i]),i-1,1);
                X.first++;
                update(i,1,X);
            }
            pair<long long,long long> X=query(r,r,1);
            if(X.first<=n && X.second==2) ++res;
        }
    }
    cout<<res<<'\n';
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T; cin>>c>>T;
    while(T--) {
        solve();
    }
    return 0;
}
