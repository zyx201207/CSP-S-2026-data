#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+1;
ll a[N],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,ans=1;
    ll w=0;
    for(int i=2;i<=n;i++){
        int l2=l;
        ll w2=w+(i-l)*(a[i]-a[i-1]);
        while(w2>m&&l2<i)l2++,w2-=(a[i]-a[l2-1]);
       w=w2, l=l2,ans=max(ans,i-l2+1);
    }
    cout<<ans;
    return 0;
}
