#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500100],pre[500100];
int sol(int ll_1,int rr_1,int mid_1){
    return (mid_1-ll_1+1)*a[mid_1]-(pre[mid_1-1]-pre[ll_1-1])-(pre[rr_1]-pre[mid_1])+a[mid_1]*(rr_1-mid_1+1);
}
int so1(int ll_1,int rr_1,int mid_1){
    return (mid_1-ll_1+1)*a[mid_1]-(pre[mid_1-1]-pre[ll_1-1])+(pre[rr_1]-pre[mid_1])-a[mid_1]*(rr_1-mid_1+1);
}
int mylb(int lll,int rrr,int xa){
    while(lll!=rrr){
        int mid=(lll+rrr)>>1;
        if(a[mid]>xa) {
            rrr=mid;
        } else {
            lll=mid+1;
        }
    }
    return lll;
}
int find_k(int ll,int rr){
    int lt=ll,rt=rr,mid=(rt+lt)>>1;
    while(a[rt]!=a[lt]){
        mid=(lt+rt)>>1;
        int an=abs(sol(ll,rr,mid)),an1=abs(sol(ll,rr,mylb(mid,rt,a[mid])));
        if(an==0) {
            lt=mid;
            rt=mid;
            break;
        }
        if(an<an1) {
            rt=mid;
        } else {
            lt=mid+1;
        }
    }
    lt=rt;
    rt=rr;
    int k=mylb(lt,rt,a[lt]);
    int an=abs(sol(ll,rr,k)),an1=abs(sol(ll,rr,rt));
    if(an1>=an) return rt;
    return k;  
}
void solve(){
    int cost=0,maxn=-1e9,ans=-1e9;
    int l=1,r=1,k=0;
    while(r<=n){
        if(r-l==1&&a[r]-a[l]>m){
            l=r;
        }
        if(so1(l,r,find_k(l,r))>m){
            l++;
            continue;
        }
        int k1=find_k(l,r+1);
        if(abs(so1(l,r+1,k1))<=m) {
            maxn=max(maxn,r-l);
            r++;
        } else {
            maxn=max(maxn,r-l+1);
            l++;
            r++;
        }
    }
    if(abs(sol(l,n,find_k(l,n)))<=m) maxn=max(maxn,r-l);
    cout<<maxn<<endl;
    return ;
}
signed main(){  
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    solve();
    return 0;
}