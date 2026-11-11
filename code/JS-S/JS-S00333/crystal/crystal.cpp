#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500005;
ll a[N];
struct node{
    int l,r,id;
    ll lazy,s;
}t[4*N];
void pushup(int id){
    t[id].s=t[id<<1].s+t[id<<1|1].s;
}
void pushdown(int id){
    if(t[id].lazy){
        t[id<<1].s+=(t[id<<1].r-t[id<<1].l+1)*t[id].lazy;
        t[id<<1|1].s+=(t[id<<1|1].r-t[id<<1|1].l+1)*t[id].lazy;
        t[id<<1].lazy+=t[id].lazy;
        t[id<<1|1].lazy+=t[id].lazy;
        t[id].lazy=0;
    }
}
void build(int id,int l,int r){
    t[id].l=l,t[id].r=r;
    if(l==r){
        t[id].s=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    pushup(id);
}
void update(int id,int x,int y,int k){
    int l=t[id].l,r=t[id].r;
    if(x<=l&&r<=y){
        t[id].lazy+=k;
        t[id].s+=(r-l+1)*k;
        return ;
    }
    pushdown(id);
    int mid=(l+r)>>1;
    if(x<=mid)update(id<<1,x,y,k);
    if(y>mid)update(id<<1|1,x,y,k);
    pushup(id);
}
int query(int id,int x,int y){
    int l=t[id].l,r=t[id].r;
    if(x<=l&&r<=y){
        return t[id].s;
    }
    pushdown(id);
    int ans=0;
    int mid=(l+r)>>1;
    if(x<=mid)ans+=query(id<<1,x,y);
    if(y>mid)ans+=query(id<<1|1,x,y);
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    build (1,1,n);
    int ans=1;
    for(int i=2;i<=n;i++){
        update(1,1,i-1,a[i]-a[i-1]);
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(1,mid,i)<=m){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<endl;
    return 0;
}
