#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
long long ch() {
    bool yon = false;
    for (int i = 1;i < n;i++) {
        if (a[i] > a[-1]) {
            swap(a[i], a[i-1]);
            yon = true;
        }
        if (!yon) break;
        ch();
    }
    if (!yon) return 0;
}
long long fi(long long ans,long long ma){
    for (int i = 1;i < n;i++) {
        while (a[i] == a[i-1]) {
            ans+=1;
            i+=1;
        }
        if (ma >= (a[i-1])){
            ma -= a[i-1];
            ans +=1;
            return fi(ans,ma);
        }
        else return ans;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> a[i];
    ch();
    long long ans = fi(0,m);
    cout << ans;
    return 0;
}
