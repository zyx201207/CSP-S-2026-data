#include <bits/stdc++.h>
using namespace std;
#define int long long
//final
int a[600005];
int s[600005];
int b[600005];
bool cmp(int a,int b) {
    return a<b;
}
signed main () {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for (int i=2;i<=n;i++) {
        b[i]=a[i]*(i-1)-s[i-1];
        if (b[i]>m) {
            ans=i-1;
            break;
        }
    }
    cout<<ans;
    return 0;
}
