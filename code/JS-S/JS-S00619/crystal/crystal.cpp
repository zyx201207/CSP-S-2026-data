#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+5);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a.begin()+1,a.begin()+n+1);
    int ans=1;
    for (int i=1,j=1,num=m;i<=n;i++) {
        while (j<n) {
            if ((a[j+1]-a[j])*(j-i+1)>num) {
                break;
            }
            num-=(a[j+1]-a[j])*(j-i+1);
            j++;
        }
        ans=max(ans,j-i+1);
        num+=a[j]-a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
