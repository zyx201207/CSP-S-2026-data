#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
struct node{
    int da,lz;
}tre[N*4];
int n,m,a[N],ans=1;
void pushdown(int i,int l,int r){
    int mid=(l+r)>>1;
    if(tre[i].lz){
        tre[i<<1].da+=tre[i].lz*(mid-l+1);
        tre[i<<1|1].da+=tre[i].lz*(r-mid);
        tre[i<<1].lz+=tre[i].lz;
        tre[i<<1|1].lz+=tre[i].lz;
        tre[i].lz=0;
    }return ;
}
void change(int i,int l,int r,int pl,int pr,int k){
    if(pl==l&&pr==r){
        tre[i].da+=(r-l+1)*k;
        tre[i].lz+=k;return ;
    }int mid=(l+r)>>1;pushdown(i,l,r);
    if(pr<=mid)change(i<<1,l,mid,pl,pr,k);
    else if(pl>mid)change(i<<1|1,mid+1,r,pl,pr,k);
    else change(i<<1,l,mid,pl,mid,k),change(i<<1|1,mid+1,r,mid+1,pr,k);
    tre[i].da=tre[i<<1].da+tre[i<<1|1].da;return ;
}
int query(int i,int l,int r,int k){
    if(l==r)return l;
    int mid=(l+r)>>1;pushdown(i,l,r);
    if(tre[i<<1|1].da<=k)return query(i<<1,l,mid,k-tre[i<<1|1].da);
    return query(i<<1|1,mid+1,r,k);
}
int query2(int i,int l,int r,int ql,int qr){
    if(ql==l&&qr==r)return tre[i].da;
    int mid=(l+r)>>1;pushdown(i,l,r);
    if(qr<=mid)return query2(i<<1,l,mid,ql,qr);
    else if(ql>mid)return query2(i<<1|1,mid+1,r,ql,qr);
    return (query2(i<<1,l,mid,ql,mid)+query2(i<<1|1,mid+1,r,mid+1,qr));
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        change(1,1,n,1,i-1,a[i]-a[i-1]);
        int ls=query(1,1,n,m);
        if(ls==1){
            if(query2(1,1,n,1,i-1)<=m)ls=0;
        }ans=max(ans,i-ls);//cout<<ls<<' ';
    }printf("%lld",ans);return 0;
}
