#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(long long l=1,r=1;l<=n;l++){
        while(r<=n&&(r-l+1)*a[r]-b[r]+b[l-1]<=m)r++;
        if((r-l+1)*a[r]-b[r]+b[l-1]<=m)ans=max(ans,r-l+1);
        else ans=max(ans,r-l);
    }
    cout << ans;
    return 0;
}
