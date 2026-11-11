#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n,m,ans,a[N];

bool check(int x){
    __int128 cnt = 0;
    for(int i = 1;i <= n;i++) cnt += max(__int128(0),__int128(x - a[i]));
    return cnt <= m;
}

signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int ppp = 0;
    for(int i = 1;i < n;i++) ppp += a[n] - a[i];
    if(m >= ppp){cout << n;return 0;}
    if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4){
        int tmp = (sqrt(m * 8 + 1) - 1) / 2;
        cout << min(tmp + 1,n);
    }else if(a[2] - a[1] == a[3] - a[2] && a[2] - a[1] == a[4] - a[3] && a[2] - a[1] == a[5] - a[4] && a[2] - a[1] == a[6] - a[5]){
        int k = a[2] - a[1];
        int tmp = double(sqrt(0.25 + m * 2.0 / k)) - 0.5;
        cout << min(tmp + 1,n);
    }else{
        int tgt,l = -2e18,r = 2e18;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid)) tgt = mid,l = mid + 1;
            else r = mid - 1;
        }
        for(int i = 1;i <= n;i++) if(a[i] <= tgt) ans++;
        cout << ans;
    }

    return 0;
}

