#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int n,m;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000) {
        int ans=1;
        for(int i=2;i<=n;i++) {
            int s=0,j;
            for(j=i-1;j>=1;j--) {
                if(s+(a[i]-a[j])>m) break;
                s+=a[i]-a[j];
            }
            ans=max(i-j,ans);
        }
        cout << ans;
    }
    else {
        int t,s=0;
        for(t=n;t>=1;t--) {
            if(a[n]-a[t]+s>m) break;
            s+=a[n]-a[t];
        }
        cout << n-t;
    }
    return 0;
}
