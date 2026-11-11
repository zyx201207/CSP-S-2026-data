#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxn=1;
    int l=1;
    ll ans=0;
    for(int r=2;r<=n;r++){
        ans+=(a[r]-a[r-1])*(r-l);
        while(l<r&&ans>m){
            ans-=(a[r]-a[l++]);
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}
