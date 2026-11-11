#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n;
long long m,a[MAXN],tree[4*MAXN],tremax[4*MAXN];
void build(int rt,int l,int r){
    if(l==r){
        tree[rt]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(rt*2,l,mid);
    build(rt*2+1,mid+1,r);
    tree[rt]=tree[2*rt]+tree[2*rt+1];
}
void buildup(int rt,int l,int r){
    if(l==r){
        tremax[rt]=a[l];
        return;
    }
    int mid=(l+r)/2;
    buildup(rt*2,l,mid);
    buildup(rt*2+1,mid+1,r);
    tremax[rt]=max(tremax[2*rt],tremax[2*rt+1]);
}
long long outpu(int rt,int l,int r,int ul,int ur){
    if(l>=ul&&r<=ur){
        return tree[rt];
    }
    int mid=(l+r)/2;
    long long res=0;
    if(ul<=mid) res+=outpu(2*rt,l,mid,ul,ur);
    if(ur>=mid+1) res+=outpu(2*rt+1,mid+1,r,ul,ur);
    return res;
}
long long getmax(int rt,int l,int r,int ul,int ur){
    if(l>=ul&&r<=ur){
        return tremax[rt];
    }
    int mid=(l+r)/2;
    long long res=-1000000000001;
    if(ul<=mid) res=max(getmax(2*rt,l,mid,ul,ur),res);
    if(ur>=mid+1) res=max(getmax(2*rt+1,mid+1,r,ul,ur),res);
    return res;
}
bool check(int l){
    long long sum=0;
    deque <int> h;
    for(int i=1;i<=l;i++){
        sum+=a[i];
        while(!h.empty()){
            int x=h.back();
            if(a[x]>a[i]) break;
            h.pop_back();
        }
        h.push_back(i);
    }
    int p=h.front();
    if(l*a[p]-sum<=m){
        return true;
    }
    for(int i=2;i+l-1<=n;i++){
        sum+=a[i+l-1];
        sum-=a[i-1];
        if(h.front()<i) h.pop_front();
        while(!h.empty()){
            int x=h.back();
            if(a[x]>a[i+l-1]) break;
            h.pop_back();
        }
        h.push_back(i+l-1);
        p=h.front();
        if(l*a[p]-sum<=m){
            return true;

        }
    }
    return false;
    /*for(int i=1;i+l-1<=n;i++){
        long long h=l*getmax(1,1,n,i,i+l-1),sum=outpu(1,1,n,i,i+l-1);
        //cout<<i<<' '<<l<<' '<<h<<' '<<sum<<endl;
        if(h-sum<=m) return true;
    }
    return false;*/
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //TREAT||TRICK
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    build(1,1,n);
    buildup(1,1,n);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    //cout<<getmax(1,1,n,1,3);
    cout<<l;
    return 0;
}
