#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5,M=3e5+5;
ll a[N],ans[M],f=1;

int main() {
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]<a[i-1]) f=0;
    }
    if(f) {
        for(ll i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
        for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(ll i=1;i<=n;i++) {
        ll boll[M]={0};
        stack<ll> stk;
        for(ll j=i;j<=n;j++) {
            if(boll[a[j]]) while(stk.top()!=a[j]) {
                boll[stk.top()]=0;
                stk.pop();
            }
            else {
                boll[a[j]]=1;
                stk.push(a[j]);
            }
        }
        for(ll j=1;j<=m;j++) ans[j]+=boll[j];
    }
    for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
