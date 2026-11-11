#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a[200005];
char c[200005];
//final
signed main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
    }
    int ans=0;
     int rev=n;
    int i=1;
    while (i<rev) {
        if (a[i]==a[rev]&&c[i]==c[rev]) {
                rev--;
                i++;
        } else if (c[i]==c[rev]) {
            if (a[i]>a[rev]) {
                rev--;
                a[i]=a[i]-rev;
            } else {
                a[rev]=a[i]-a[rev];
                i++;
            }
        } else if (c[i]==c[rev]) {
            ans+=a[i];
            i++;
            rev--;
        } else {
            if (a[i]>a[rev]) {
                ans+=a[rev];
                a[i]=a[i]-a[rev];
                rev--;
            } else {
                ans+=a[i];
                a[rev]=a[i]-a[rev];
                i++;
            }
        }

    }
    cout<<ans;
    return 0;
}
