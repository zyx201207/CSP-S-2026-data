#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
const ll mx = 1e12;
int n;
ll m;
ll a[N];
ll c[N];
int ans;
bool ck(int x,int r){
    return a[r]*(r-x+1)-c[r]+c[x-1]<=m;
}
int ef(int l,int r){
    int al=r;
    int rr=r;
    while(l<=r){
        int mid=(l+r)>>1;
        bool b=ck(mid,rr);
        if(b)
            al=min(al,mid);
        if(b)
            r=mid-1;
        else
            l=mid+1;
    }
    return al;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=a[i]+c[i-1];
        int l=ef(1,i);
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}