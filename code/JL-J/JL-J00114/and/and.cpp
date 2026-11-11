#include<bits/stdc++.h>
using namespace std;
long long i=1,n,m,a[200100],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    for(i=1;i<=n;i++){
        for(long long j=i;j<=m;j++){
            ans=max(ans,a[i]&a[i+1]);
        }
    }
    cout << ans;
    return 0;
}
