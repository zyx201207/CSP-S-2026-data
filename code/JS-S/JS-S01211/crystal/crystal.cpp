#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5e5+5;
ll n,m,a[N],dif[N],qzh[N];
bool check(int len){
    ll mncost=0,lstcost;
    int it=2;
    for(int i=1;i<len;i++) mncost+=dif[i]*i;
    lstcost=mncost;
    for(int i=2;i+len-1<=n;i++){
        ll cost=lstcost;
        cost-=(qzh[i+len-3]-qzh[i-2]);
        cost+=dif[i+len-2]*(len-1);
        mncost=min(mncost,cost);
        lstcost=cost;
    }
    return mncost<=m;
}
int main(){
    freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) dif[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++) qzh[i]=dif[i]+qzh[i-1];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}
