#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],e[N*4],sum[N*4],ans=1,pc=1;
void bd(int p,int l,int r){
    if(l==r){
        e[p]=b[l];
        return ;
    }
    int mid=(l+r)>>1;
    bd(p<<1,l,mid);
    bd(p<<1|1,mid+1,r);
    e[p]=e[p<<1]+e[p<<1|1];
    return ;
}
void ce(int p,int l,int r,int l1,int r1,int k){
    if(l1<=l&&r1>=r){
        sum[p]+=k;
        return ;
    }
    int mid=(l+r)>>1;
    if(l1<=mid)ce(p<<1,l,mid,l1,r1,k);
    if(r1>mid)ce(p<<1|1,mid+1,r,l1,r1,k);
    e[p]=e[p<<1]+(mid-l+1)*sum[p<<1]+e[p<<1|1]+(r-mid)*sum[p<<1|1];
    return ;
}
int ck(int p,int l,int r,int l1,int r1){
    if(l1<=l&&r1>=r)return e[p]+(r-l+1)*sum[p];
    int cnt=0,mid=(l+r)>>1;
    sum[p<<1]+=sum[p];
    sum[p<<1|1]+=sum[p];
    sum[p]=0;
    if(l1<=mid)cnt+=ck(p<<1,l,mid,l1,r1);
    if(r1>mid)cnt+=ck(p<<1|1,mid+1,r,l1,r1);
    e[p]=e[p<<1]+(mid-l+1)*sum[p<<1]+e[p<<1|1]+(r-mid)*sum[p<<1|1];
    return cnt;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    if(b[1]<=m)ans=2;
    bd(1,1,n-1);
    for(int i=2;i<n;i++){
        ce(1,1,n-1,1,i-1,b[i]);
        int l=pc,r=i-max(ans-1,1ll),na=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int cnt=ck(1,1,n-1,mid,i);
            if(cnt<=m){
                na=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
                pc=max(pc,l);
            }
        }
        if(na!=-1)ans=max(ans,i-na+2);
    }
    cout<<ans;
    return 0;
}
