#include <bits/stdc++.h>
using namespace std;
long long ans,mx;
int n,m;
long long a[5050];
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(i>1) {
            ans=(ans&a[i]);
        }else {
            ans=a[i];
        }
        mx=max(a[i],mx);
    }
    if(m==1) {
        cout<<mx;
    }else if(m==2) {
        mx=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if((a[i]&a[j])>mx&&i!=j) mx=(a[i]&a[j]);
            }
        }
        cout<<mx;
    }else {
        cout<<ans;
    }
    return 0;
}
