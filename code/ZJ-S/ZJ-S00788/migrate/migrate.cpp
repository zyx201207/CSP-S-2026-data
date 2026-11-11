#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e6+6,M=5e3+6;
const ll INF=4e18;
int n;
ll m,a[N];
int pre[N];
ll dp[M][M],cnt[M][M],s[N];
int find_pre(int pos) {
    int l=1,r=pos;
    while (l<r) {
        int mid=((l+r)>>1);
        if (a[pos]-a[mid]<=m) r=mid; else l=mid+1;
    }
    return l;
}
struct Tree {
    ll mn;
    int cnt;
    Tree operator + (const Tree &o) const {
        if (mn<o.mn) return *this; 
        if (o.mn<mn) return o;
        return {mn,o.cnt+cnt};
    }
};
struct SegTree{
    Tree tr[N<<2];
    #define ls (u<<1)
    #define rs (u<<1|1)
    #define mid ((l+r)>>1)
    void push_up(int u) {tr[u]=tr[ls]+tr[rs];} 
    void build (int u,int l,int r) {
        tr[u]={INF,0};
        if (l==r) return;
        build(ls,l,mid); build(rs,mid+1,r);
    }
    void update (int u,int l,int r,int p,int val,int c) {
        if (l==r) {tr[u]={val,c}; return;}
        if (p<=mid) update(ls,l,mid,p,val,c); else update(rs,mid+1,r,p,val,c);
        push_up(u);
    }
    Tree query (int u,int l,int r,int ql,int qr) {
        if (ql<=l && r<=qr) return tr[u];
        if (qr<=mid) return query(ls,l,mid,ql,qr);
        if (ql>mid) return query(rs,mid+1,r,ql,qr);
        return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
    }
    #undef ls
    #undef rs
    #undef mid 
}tr;
void solve_brute() {
    for (int i=1;i<=n;++i) pre[i]=find_pre(i);
    int res=0;
    for (int l=1;l<=n;++l) {
        tr.build(1,l,n);
        tr.update(1,l,n,l,0,1);
        for (int r=l+1;r<=n;++r) {
            if (pre[r]>=r) break;
            Tree ans=tr.query(1,l,n,pre[r],r-1);
            if (ans.cnt==2) res++;
            tr.update(1,l,n,r,ans.mn+1,ans.cnt);
        }
    }
    cout<<res<<"\n";
} //n^2logn->nlogn
bool check_special_A () {
    for (int i=3;i<=n;++i) if (a[i]-a[i-1]!=a[2]-a[1]) return 0;
    return 1; 
}
void solve_special_A () {
    ll d=a[2]-a[1];
    ll mx_step=m/d;
    if (mx_step<=1) {
        cout<<"0\n";
        return;
    }
    //mx_step*2-1
    ll res=n-(mx_step*2-1);
//    cout<<d<<" "<<mx_step<<"\n";
    cout<<max(0ll,res)<<"\n";
}
bool check_special_B() {
    for (int i=1;i<=n;++i) if (a[i]-a[1]<=m && a[n]-a[i]<=m) return 1;
    return 0;
}
int find_nex(int pos) {
    int l=pos,r=n;
    while (l<r) {
        int mid=((l+r+1)>>1);
        if (a[mid]-a[pos]<=m) l=mid; else r=mid-1;
    }
    return l;
}
void solve_special_B() {
    for (int i=1;i<=n;++i) pre[i]=find_pre(i),s[i]=0;
    for (int i=1;i<=n;++i) s[pre[i]]++;
    ll res=0;
    for (int i=1;i<=n;++i) {
        int t=find_nex(i);
        if (t==i || t==i+1) continue;
        res+=s[t-1];
    }
    cout<<res<<"\n";
}
void Solve () { 
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    if (check_special_A()) {solve_special_A(); return;}
    if (check_special_B()) {solve_special_B(); return;}
    if (n<=5000) {solve_brute(); return; }
    cout<<1ll*n*(n-1)/2<<"\n"; 
} 
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,T=1; cin>>c>>T;
    while (T--) Solve();
    return 0;
}

