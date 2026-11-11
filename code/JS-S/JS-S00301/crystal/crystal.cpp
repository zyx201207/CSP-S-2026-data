#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 5e5+10;
ll a[maxN],pre[maxN],n,m,ans;
inline bool check(ll l,ll r){
    ll mid = r;
    ll tmp1 = a[mid]*(mid-l)-(pre[mid-1]-pre[l-1]);
    ll tmp2 = pre[r]-pre[mid]-a[mid]*(r-mid);
    return m >= tmp1+tmp2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) pre[i] = a[i]+pre[i-1];
    ll l = 1;
    for(ll r = 1;r <= n;r++){
        while(!check(l,r)) l++;
        ans = max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
