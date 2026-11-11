#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define dep(i,e,s) for(int i=e;i>=s;i--)
#define lc id<<1
#define rc id<<1|1
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int maxn=2e6+10;
const ll inf=5e18;
int n;
ll d,x[maxn];
// ll f[maxn][2];
// void solve(){
//     cin>>n>>d;
//     rep(i,1,n) cin>>x[i],f[i][0]=f[i][1]=0;
//     x[n+1]=inf;
//     ll ans=0;
//     rep(i,1,n){
//         ll t=min(x[i],x[i+1]-d);
//         rep(j,1,i-1){
//             if(x[j]>=x[i]-d&&x[j]<t)
//                 f[i][0]++;
//         }
//         rep(j,2,i-1){
//             if(x[j]>=x[i]-d&&x[j]<t&&x[j-1]<x[i]-d){
//                 f[i][0]+=f[j][0];
//                 f[i][1]+=f[j][1];
//             }
//         }
//         rep(j,3,i-1){
//             if(x[j]<t&&x[j-1]>=x[i]-d&&x[j-2]<x[i]-d)
//                 f[i][1]+=f[j][0];
//         }
//         rep(j,2,i-1) if(x[i]-d<=x[j]&&x[j-1]<x[i]-d) ans+=f[j][1];
//         rep(j,3,i-1) if(x[i]-d<=x[j]&&x[j-1]>=x[i]-d&&x[j-2]<x[i]-d) ans+=f[j][0];
//     }
//     cout<<ans<<"\n";
// }
struct node{
    int l,r;
    ll v1,v2;
}s[maxn*4];
void build(int id,int l,int r){
    s[id].l=l;s[id].r=r;s[id].v1=0;s[id].v2=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(lc,l,mid);
    build(rc,mid+1,r);
}
inline void modify1(int id,int pos,ll v){
    if(s[id].l==pos&&s[id].r==pos){
        s[id].v1+=v;
        return;
    }
    int mid=(s[id].l+s[id].r)/2;
    if(pos<=mid) modify1(lc,pos,v);
    else modify1(rc,pos,v);
    s[id].v1=s[lc].v1+s[rc].v1;
}
inline void modify2(int id,int pos,ll v){
    if(s[id].l==pos&&s[id].r==pos){
        s[id].v2+=v;
        return;
    }
    int mid=(s[id].l+s[id].r)/2;
    if(pos<=mid) modify2(lc,pos,v);
    else modify2(rc,pos,v);
    s[id].v2=s[lc].v2+s[rc].v2;
}
inline ll query1(int id,int l,int r){
    if(l>r) return 0;
    if(s[id].l>=l&&s[id].r<=r) return s[id].v1;
    int mid=(s[id].l+s[id].r)/2;
    ll ans=0;
    if(l<=mid) ans+=query1(lc,l,r);
    if(r>=mid+1) ans+=query1(rc,l,r);
    return ans;
}
inline ll query2(int id,int l,int r){
    if(l>r) return 0;
    if(s[id].l>=l&&s[id].r<=r) return s[id].v2;
    int mid=(s[id].l+s[id].r)/2;
    ll ans=0;
    if(l<=mid) ans+=query2(lc,l,r);
    if(r>=mid+1) ans+=query2(rc,l,r);
    return ans;
}
inline int lb(ll v){
    return lower_bound(x+1,x+n+1,v)-x;
}
inline int ls(ll v){
    return lower_bound(x+1,x+n+1,v)-x-1;
}
void solve2(){
    cin>>n>>d;
    rep(i,1,n) cin>>x[i];
    x[n+1]=inf;
    build(1,1,n);
    ll ans=0;
    rep(i,1,n){
        ll t=min(x[i],x[i+1]-d),l,r;
        int x1=ls(x[i]-d),x2=ls(t);
        l=lb(x[i]-d),r=x2;
        if(l<=r) modify1(1,i,r-l+1);
        r=min(x2,x1+1);
        modify1(1,i,query1(1,l,r));
        modify2(1,i,query2(1,l,r));
        l++,r=min(x2,x1+2);
        modify2(1,i,query1(1,l,r));
        l--,r=min(i-1,x1+1);
        ans+=query2(1,l,r);
        l++,r=min(i-1,x1+2);
        ans+=query1(1,l,r);
    }
    cout<<ans<<"\n";
}
int c,T;
signed main(){
    freopen("migrate.in","r",stdin);    
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c;
    cin>>T;
    while(T--){
        solve2();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/