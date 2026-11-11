#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define mid ((tree[rt].l+tree[rt].r)>>1)
using namespace std;
const int MAXN=5e5+10;
const int INF=2147483647;
int n,m,a[MAXN];
int pos[MAXN],last[MAXN];
int ans[MAXN];
bool f=0;
struct node{
    int l,r,ali,die,near;
}tree[MAXN*4];
void push_up(int rt){
    tree[rt].near=max(tree[ls].near,tree[rs].near);
}
void setali(int rt,int k){
    tree[rt].ali=min(tree[rt].ali,k);
}
void setdie(int rt,int k){
    tree[rt].die=min(tree[rt].die,k);
    if(tree[rt].l==tree[rt].r&&(f||tree[rt].die!=n+1)){
        ans[a[tree[rt].l]]+=max(tree[rt].die-tree[rt].ali,0);
        tree[rt].ali=tree[rt].die=n+1;
    }
}
void push_down(int rt){
    setali(ls,tree[rt].ali);
    setali(rs,tree[rt].ali);
    setdie(ls,tree[rt].die);
    setdie(rs,tree[rt].die);
    tree[rt].ali=tree[rt].die=n+1;
}
void build(int rt,int l,int r){
    tree[rt].ali=tree[rt].die=n+1;
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)return;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updateAli(int rt,int l,int r,int k){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        setali(rt,k);
        return;
    }
    push_down(rt);
    if(l<=mid)updateAli(ls,l,r,k);
    if(r>mid)updateAli(rs,l,r,k);
}
void updateDie(int rt,int l,int r,int k){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        setdie(rt,k);
        return;
    }
    push_down(rt);
    if(l<=mid)updateDie(ls,l,r,k);
    if(r>mid)updateDie(rs,l,r,k);
}
void updateNear(int rt,int x,int k){
    if(tree[rt].l==x&&tree[rt].r==x){
        tree[rt].near=k;
        return;
    }
    if(x<=mid)updateNear(ls,x,k);
    else updateNear(rs,x,k);
    push_up(rt);
}
int queryNear(int rt,int l,int r){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        return tree[rt].near;
    }
    int res=0;
    if(l<=mid)res=max(res,queryNear(ls,l,r));
    if(r>mid)res=max(res,queryNear(rs,l,r));
    return res;
}
void dfs(int rt){
    if(tree[rt].l==tree[rt].r)return;
    push_down(rt);
    dfs(ls);
    dfs(rs);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        updateNear(1,i,last[a[i]]);
        last[a[i]]=i;
        updateAli(1,i,i,n-i+1);
        if(pos[a[i]]){
            updateDie(1,i,pos[a[i]]-1,n-i+1);
            updateAli(1,pos[a[i]],queryNear(1,i,pos[a[i]]-1),n-i+1);
        }
        else pos[a[i]]=i;
    }
    f=1;
    dfs(1);
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
//g++ card.cpp -o card -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576 && ulimit -s 1048576 && time ./card