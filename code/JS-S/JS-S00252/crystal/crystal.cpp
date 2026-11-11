#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500010;
int a[N];
int n, m;

int check(int cnt){
    int ans = 1e18;
    int now = 0;
    for (int i = cnt; i <= n; i++){
        if (i == cnt){
            for (int j = 1; j < cnt; j++){
                now += a[i]-a[j];
            }
        }
        else{
            now -= a[i-1]-a[i-cnt];
            now += (cnt-1)*(a[i]-a[i-1]);
        }
        if (now < ans) ans = now;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int l = 1, r = n;
    while(l < r){
        int mid = (l+r)/2+1;
        if (check(mid) <= m){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << l << '\n';

    return 0;
}
