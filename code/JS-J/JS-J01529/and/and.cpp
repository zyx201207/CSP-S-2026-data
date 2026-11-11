#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn = INT_MIN;
        for(int i=1;i<=n;i++){
            maxn = max(maxn,a[i]);
        }
        cout<<maxn<<endl;
        return 0;
    }
    if(m == n){
        int ans = a[1] && a[2];
        for(int i=3;i<=n;i++){
            ans = ans && a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
