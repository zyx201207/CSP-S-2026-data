#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+5;
int n;
ll a[N],sum;
char c[N];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r) {
        ll t=min(a[l],a[r]);
        if(c[l]!=c[r])sum+=t;
        a[l]-=t,a[r]-=t;
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<sum;
    return 0;
}
