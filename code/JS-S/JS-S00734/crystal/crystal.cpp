#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m;
int ans=1;
int a[N];
int s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        s[i] = s[i-1]+a[i];
    }
    int l = 1;
    for(int r = 2;r<=n;r++){
        while(l<=r&&a[r]*(r-l)-(s[r-1]-s[l-1])>m) l++;
        ans = max(ans,r-l+1);
    }
    cout << ans;
    return 0;
}