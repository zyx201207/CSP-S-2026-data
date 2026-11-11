#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++i)
const ll N=2e6+10;

ll c,n,t,d,a[N],f[N],ans=0,l[N],tr[N<<2],pos[N];

#define ls p<<1
#define rs p<<1|1
#define mid (l+r>>1)
void build_tree(int p,int l,int r){
    tr[p]=0;
    if(l==r) return;
    build_tree(ls,l,mid);
    build_tree(rs,mid+1,r);
}
void pushup(int p){
    tr[p]=min(tr[ls],tr[rs]);
}
void update(int p,int l,int r,int nl,int nr,int k){
    if(nl<=l&&r<=nr){
        tr[p]+=k;
        return;
    }
    if(nl<=mid) update(ls,l,mid,nl,nr,k);
    if(mid<nr) update(rs,mid+1,r,nl,nr,k);
    pushup(p);
}
ll query(int p,int l,int r,int nl,int nr){
    if(nl>nr) return 0;
    if(nl<=l&&r<=nr){
        return tr[p];
    }
    ll res=0x3f3f3f3f3f3f3f3f;
    if(nl<=mid) res=min(res,query(ls,l,mid,nl,nr));
    if(mid<nr) res=min(res,query(rs,mid+1,r,nl,nr));
    pushup(p);
    return res;
}
void solve1(){
    ans=0;
    for(int st=1;st<=n;++st){
        build_tree(1,1,n);
        rep(k,0,n) f[k]=l[k]=0,pos[k]=0;
        int i=st,j=st;
        for(;j<=n;++j){
            while(a[j]-a[i]>d){
                l[pos[i]]-=f[i];
                i++;
            }
            ll len=query(1,1,n,i,j-1);
            f[j]=l[len];
            if(j==st) f[j]=1;
            pos[j]=len+1;
            l[pos[j]]+=f[j];
            update(1,1,n,j,j,pos[j]);
        }
        // cout<<st<<'\n';
        rep(k,1,n){
            // cout<<f[k]<<' ';
            if(f[k]==2) ans++;
        } 
        // cout<<'\n';
    }
    cout<<ans<<'\n';
}
void solve2(){
    ans=0;
    for(int st=1;st<=1;++st){
        build_tree(1,1,n);
        rep(k,0,n) f[k]=l[k]=0,pos[k]=0;
        int i=st,j=st;
        for(;j<=n;++j){
            while(a[j]-a[i]>d){
                l[pos[i]]-=f[i];
                i++;
            }
            ll len=query(1,1,n,i,j-1);
            f[j]=l[len];
            if(j==st) f[j]=1;
            pos[j]=len+1;
            l[pos[j]]+=f[j];
            update(1,1,n,j,j,pos[j]);
        }
        // cout<<st<<'\n';
        rep(k,1,n){
            // cout<<f[k]<<' ';
            if(f[k]==2) ans+=1ll*(n-k+1);
        } 
        // cout<<'\n';
    }
    cout<<ans<<'\n';
}
void solve3(){
    ans=0;
    rep(i,1,n){
        l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
        pos[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    }
    int i=1,j=1;
    for(;j<=n;++j){
        while(pos[i]<l[j]+1) i++; 
        if(pos[i]>l[j]+1) continue;
        if(pos[i]==l[j]+1) ans++;
    }
    cout<<ans<<'\n';
}
void solve4(){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        rep(i,1,n) cin>>a[i];
        if(1<=c&&c<=10) solve1();
        if(c==11||c==12) solve2();
        if(c==13||c==14) solve3();
        if(15<=c) solve4();
    }

    return 0;
}
/*
13 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/