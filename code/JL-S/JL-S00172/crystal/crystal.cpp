#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a+1,a+n+1);
    int sum = 0,ans=0,l=1;
    for(int i = 1; i <= n; i++){
        sum+=a[i];
        while(a[i]*(i-l+1)-sum>m)sum-=a[l++];
        ans=max(ans,i-l+1);
    }
    cout << ans<<"\n";
    return 0;
}