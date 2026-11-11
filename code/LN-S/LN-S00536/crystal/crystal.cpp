#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    
    ll sum=0;
    int ans=1;
    for(int l=1,r=1;r<=n;r++) {
        sum+=a[r];
        while(l<r&&a[r]*(r-l+1)-sum>m) {
            sum-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}