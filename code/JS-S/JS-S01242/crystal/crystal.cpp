#include <bits/stdc++.h>
using namespace std;

long long n,m,ans,curr;
long long a[500005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for( long long i = 1; i <= n; i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l = 1, r=2;
    long long needm=a[2]-a[1];
    if(needm<=m)ans=2;
    else ans=1;
    while(l<=r&&r<=n) {
        if(needm + ((r+1)-l)*(a[r+1]-a[r])<=m){
            needm=needm + ((r+1)-l)*(a[r+1]-a[r]);
            r++;
            ans=max(ans,r-l+1);
        }
        else {
            needm = needm - (a[r]-a[l]);
            l++;
            if(needm<=m){
                ans=max(ans,r-l+1);
            }

        }

    }
    cout << ans;
    

    
    return 0;
}