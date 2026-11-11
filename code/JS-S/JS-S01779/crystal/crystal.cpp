#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int n,m,a[N+5],p,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=a[n];
    p=n+1;
    for(int i=n;i>=1;i--){
        m+=(i-p+1)*(a[i+1]-a[i]);
        while(p>1 && m>=a[i]-a[p-1]){
            m-=a[i]-a[p-1];
            p--;
        }
        ans=max(ans,i-p+1);
    }
    cout << ans;
    return 0;
}