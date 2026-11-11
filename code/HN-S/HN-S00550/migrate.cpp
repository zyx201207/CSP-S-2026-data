#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 2001114
map<pair<int,int>,int>mp;
int tc,t,n,a[N],d,pre[N],suf[N],f[N],g[N],dis[N];
struct stu{int l,r,sum,tag;};
vector<int>to[N];
struct segtree{
    #define ls p<<1
    #define rs p<<1|1
    stu t[N<<2];
    void addtag(int p,int k){t[p].sum=k*(t[p].r-t[p].l+1);t[p].tag=k;}
    void pushdown(int p){if(t[p].tag!=-1){addtag(ls,t[p].tag);addtag(rs,t[p].tag);t[p].tag=-1;}}
    void pushup(int p){t[p].sum=t[ls].sum+t[rs].sum;}
    void build(int p,int l,int r){
        t[p].l=l;t[p].r=r;t[p].sum=0;t[p].tag=-1;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(ls,l,mid);build(rs,mid+1,r);
    }
    void update(int p,int l,int r,int k){
        if(l>r)return;
        if(l<=t[p].l&&t[p].r<=r){addtag(p,k);return;}
        pushdown(p);
        if(l<=t[ls].r)update(ls,l,r,k);
        if(r>=t[rs].l)update(rs,l,r,k);
        pushup(p);
    }
    void _update(int p,int x,int k){
        if(t[p].l==t[p].r){t[p].sum+=k;return;}
        pushdown(p);
        if(x<=t[ls].r)_update(ls,x,k);
        else _update(rs,x,k);
        pushup(p);
    }
    int ask(int p,int l,int r){
        if(l>r)return 0;
        if(l<=t[p].l&&t[p].r<=r)return t[p].sum;
        pushdown(p);
        int s=0;
        if(l<=t[ls].r)s+=ask(ls,l,r);
        if(r>=t[rs].l)s+=ask(rs,l,r);
        return s;
    }
    #undef ls
    #undef rs
}t1;
void calc(int *f,int *pre){
    t1.build(1,1,n);
    rep(i,1,n){
        int l=1,r=i-1,px=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]-a[mid]<=d){px=mid;r=mid-1;}
            else l=mid+1;
        }
        pre[i]=px;
    }
    int ans=0;
    rep(i,1,n){
        t1.update(1,1,pre[pre[i]]-1,0);
        if(pre[i]+1==i){
            int s=t1.ask(1,1,pre[i]-1);
            t1._update(1,pre[i],s);
        }
        else{
            if(pre[i]+2==i){
                int s=t1.ask(1,1,pre[pre[i]+1]-1);
                t1._update(1,pre[i],s);
            }
            else if(pre[i]+2<i){
                int s=t1.ask(1,1,pre[pre[i]+1]-1);
                t1._update(1,pre[i],s);
            }
        }
        t1.update(1,1,pre[i]-1,0);
        t1._update(1,i,1);
        f[i]=t1.t[1].sum;
    }
}
void sub40(){
    rep(i,1,n)to[i].clear();
    rep(i,1,n){
        per(j,i-1,1){
            if(a[i]-a[j]>d)break;
            to[i].push_back(j);
        }
        rep(j,i+1,n){
            if(a[j]-a[i]>d)break;
            to[i].push_back(j);
        }
    }
    int ans=0;
    rep(i,1,n){
        queue<int>q;
        rep(j,1,n)f[j]=0,dis[j]=-1;
        q.push(i);dis[i]=0;f[i]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int y:to[x]){
                if(dis[y]==-1){
                    dis[y]=dis[x]+1;
                    f[y]=f[x];
                    q.push(y);
                }
                else{if(dis[y]==dis[x]+1)f[y]+=f[x];}
            }
        }
        rep(j,1,n)if(f[j]==2){ans++;}
    }
    cout<<ans/2<<'\n';
}
void solve(){
    cin>>n>>d;rep(i,1,n)cin>>a[i];mp.clear();
    if(n<=5000){
        sub40();
        return;
    }
    calc(f,pre);reverse(a+1,a+n+1);rep(i,1,n)a[i]=-a[i];
    calc(g,suf);reverse(a+1,a+n+1);rep(i,1,n)a[i]=-a[i];
    rep(i,1,n)suf[i]=n-suf[i]+1;reverse(suf+1,suf+n+1);reverse(g+1,g+n+1);
    int ans=0;
    rep(i,1,n){
        if(pre[i]+1>=i)continue;
        int x=pre[pre[i]+1];
        if(x==pre[i])continue;
        if(suf[x]>pre[i]+1)continue;
        mp[{x,i}]=1;
        int l=f[pre[x]],r=g[suf[i]];
        if(i!=suf[pre[i]]){r=0;}
        if(x!=pre[suf[x]]){l=0;}
        if(suf[pre[x]]!=x){l=0;}
        if(pre[suf[i]]!=i){r=0;}
        ans+=(l+1)*(r+1);
    }
    per(i,n,1){
        if(suf[i]-1<=i)continue;
        int x=suf[suf[i]-1];
        if(x==suf[i])continue;
        if(pre[x]<suf[i]-1)continue;
        if(mp.count({i,x}))continue;
        mp[{i,x}]=1;
        int l=f[pre[i]],r=g[suf[x]];
        if(i!=suf[pre[i]]){l=0;}
        if(x!=pre[suf[x]]){r=0;}
        if(suf[pre[x]]!=x){r=0;}
        if(pre[suf[i]]!=i){l=0;}
        ans+=(l+1)*(r+1);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>tc>>t;while(t--)solve();
}