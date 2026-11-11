#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+10;
int n,m;
int arr[N];
int diff[N];
void solve45pts(){
    sort(arr+1,arr+1+n);
    int res=0;
    for(int i=1;i<=n;i++){
        int sum=0,cnt=1;
        for(int j=i-1;j>=1;j--){
            if(sum+arr[i]-arr[j]>m){
                break;
            }else{
                sum+=(arr[i]-arr[j]);
                cnt++;
            }
        }
        res=max({res,cnt});
    }cout<<res<<'\n';
}
struct SegTree{
    int val,tag;
}tr[N*4];
void pushup(int u){
    tr[u].val=tr[u*2].val+tr[u*2+1].val;
}
/*
void build(int u,int l,int r){
    tr[u].tag=0;
    if(l==r){
        tr[u].val=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(u*2,l,mid);
    build(u*2,mid+1,r);
    pushup(u);
}
*/
bool in_range(int l,int r,int ql,int qr){
    return (ql<=l) && (r<=qr);
}
bool out_range(int l,int r,int ql,int qr){
    return (l>qr) || (r<ql);
}
void maketag(int u,int l,int r,int x){
    int len=r-l+1;
    tr[u].val+=len*x;
    tr[u].tag+=x;
}
void pushdown(int u,int l,int r){
    if(tr[u].tag){
        int mid=(l+r)>>1;
        maketag(u*2,l,mid,tr[u].tag);
        maketag(u*2+1,mid+1,r,tr[u].tag);
        tr[u].tag=0;
    }
}
int query(int u,int l,int r,int ql,int qr){
    if(in_range(l,r,ql,qr)){
        return tr[u].val;
    }else if(!out_range(l,r,ql,qr)){
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        return query(u*2,l,mid,ql,qr)+query(u*2+1,mid+1,r,ql,qr);
    }else{
        return 0;
    }
}
void update(int u,int l,int r,int ql,int qr,int x){
    if(in_range(l,r,ql,qr)){
        maketag(u,l,r,x);
        return ;
    }else if(!out_range(l,r,ql,qr)){
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        update(u*2,l,mid,ql,qr,x);
        update(u*2+1,mid+1,r,ql,qr,x);
        pushup(u);
    }else{
        return ;
    }
}
void solve_std(){
    sort(arr+1,arr+1+n);
    int ans=0;
    for(int i=2;i<=n;i++){
        diff[i]=arr[i]-arr[i-1];
    }
    for(int i=1;i<=n;i++){
        if(i!=1) update(1,1,n,1,i-1,diff[i]);
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(1,1,n,mid,i)<=m) r=mid;
            else l=mid+1;
        }
        ans=max({ans,i-l+1});
    }cout<<ans<<'\n';
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    //cerr<<fixed<<setprecision(4)<<log(2.5e11)/log(2)*5e5<<'\n'; exit(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n<=5000){
        solve45pts();
        return 0;
    }else{
        solve_std();
        return 0;
    }
    return 0;
}
/*
RP++
14:44 45pts
14:51 SegmentTree
15:11 WA on cry4
15:15 fixed bug,but TLE(6.4s) on cry4 ?
15:18 i believe [] can 1s big changshu 2e7,let me ac plz QAQ
16:42 duipai Accepted
*/
