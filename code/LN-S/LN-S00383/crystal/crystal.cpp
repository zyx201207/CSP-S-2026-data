#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a.begin() + 1,a.end());
    vector<ll> pre(n + 1);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
    }
    auto calc = [&](int pos) -> int {
        int l = 1,r = pos;
        while(l < r){
            int mid = (l + r) >> 1;
            if(a[pos] * ((ll)pos - (ll)mid) - (pre[pos - 1] - pre[mid - 1]) <= m) r = mid;
            else l = mid + 1;
        }
        return r;
    };
    int ans = 1;
    for(int i = 2;i <= n;i++){
        ans = max(ans,i - calc(i) + 1);
    }
    cout<<ans;
    return 0;
}
// g++ crystal.cpp -o crystal -std=c++14
