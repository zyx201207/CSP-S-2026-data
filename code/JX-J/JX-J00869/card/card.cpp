#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],t[M],ans[M];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
int tree[N<<2],lazy[N<<2];
void p_d(int p){
    if(lazy[p]){
        lazy[ls(p)]=max(lazy[p],lazy[ls(p)]);
        lazy[rs(p)]=max(lazy[p],lazy[rs(p)]);
    }
}
void updata(int p,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        lazy[p]=max(lazy[p],k);
        return;
    }
    p_d(p);
    int mid=l+r>>1;
    if(mid>=L) updata(ls(p),l,mid,L,R,k);
    if(mid<R) updata(rs(p),mid+1,r,L,R,k);
}
void build(int p,int l,int r){
    if(l==r){
        tree[p]=lazy[p];
        return;
    }
    p_d(p);
    int mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
}
int query(int p,int l,int r,int idx){
    if(l==r){
        return tree[p];
    }
    int mid=l+r>>1;
    if(idx<=mid) return query(ls(p),l,mid,idx);
    else return query(rs(p),mid+1,r,idx);
}
struct node{
    int l,r;
    bool operator< (const node& other) const{
        return l<other.l;
    }
};
vector<node> v[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(t[a[i]]) updata(1,1,n,t[a[i]]+1,i-1,t[a[i]]);
        if(a[i]<a[i-1]) f=0;
        t[a[i]]=i;
    }
    if(f){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) printf("%d",ans[i]);
        return 0;
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        v[a[i]].push_back({query(1,1,n,i),i});
    }
    for(int i=1;i<=m;i++) sort(v[i].begin(),v[i].end());
    for(int i=1;i<=m;i++){
        int ans=0,mr=0;
        for(auto j:v[i]){
            ans+=max(j.r-max(j.l,mr),0);
            mr=max(mr,j.r);
        }
        printf("%d ",ans);
    }
    return 0;
}
