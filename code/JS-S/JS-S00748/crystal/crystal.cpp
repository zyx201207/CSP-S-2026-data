#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

typedef unsigned long long ll;

ll n,m;
ll a[N], b[N], sum[N];

int find(int x) {
    int i = 1;
    for(i=1;i<=n;i++){
        if(a[i]>x) break;
    }
    return i-1;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll ans=LLONG_MIN;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) flag = false;
    }
    bool flag1 = true;
    ll x = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] != x) flag1 = false;
    }
    if (flag == true) {
        ll ans1;
        for (ans1 = 1; ans1 * (ans1 + 1) / 2 <= m; ans1++);
        cout << ans1;
    }
    else if (flag1 == true){
        ll ans2;
        for (ans2 = 1; ans2 * (a[1] + (ans2 - 1) * x + a[1]) / 2 <= m; ans2++);
        cout << ans2;
    }
    else if(a[n]-a[1]<=100){
        for(ll i=a[1];i<=a[n];i++){
            ll sum=0;
            int pos=find(i);
            long long tmp = m;
            for(int j=pos;j>=1;j--){
                if(a[pos]-a[j]<=tmp){
                    tmp-=a[pos]-a[j];
                    sum++;
                } else {
                    break;
                }
            }
            ans = max(ans,sum);
        }
        cout<<ans;
    }
    else {
        for(int i = 1; i <= n - 1; i++) {
            b[i] = a[i+1] - a[i];
        }
        b[n] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + b[i];
        }
        int maxn = INT_MIN;
        for (int i = 1; i<=n; i++) {
            for(int j = i; j <= n; j++) {
                if (sum[j] - sum[i - 1] <= m && sum[j] >= 0 && sum[i - 1] >= 0 && sum[j] - sum[i - 1] >= 0) maxn = max(maxn, j-i+1);
            }
        }
        cout<<maxn;
    }
    return 0;
}
