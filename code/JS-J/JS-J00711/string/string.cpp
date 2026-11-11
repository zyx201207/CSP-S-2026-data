#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[200005];
string c[200005];
int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i] >> c[i];
    }
    if(n==1) {
        cout << "0";
        return 0;
    } else if(n==2) {
        ans=min(a[0],a[1]);
        cout << ans;
    }
    for (int i=0;i<=n;i++) {
        if(c[i]!=c[n-i])
            if(a[i]==a[n-i]) {
                ans=ans + a[i];
            }else{
                ans=ans+min(a[i],a[n-i]);
                if(a[i]<=a[n-i]) {
                    a[n-i]=a[n-i]-a[i];
                    n=n+1;
                }else{
                    a[i]=a[i]-a[n-i];
                    n=n-1;
                }
            }
    }
    cout << ans<<endl;
}
