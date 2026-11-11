#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
constexpr int N = 1e6+10;
int n,m;
int a[N],s[N],ans;
bool check(int l,int r){
    int len = r - l + 1;
    return a[r] * len - (s[r] - s[l - 1]) <= m;
}
bool check1(int x){
    for(int i = 1;i + x - 1 <= n;i++){
        if(x * a[i + x - 1] - (s[i + x - 1] - s[i - 1]) <= m) return 1;
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        s[i] = s[i - 1] + a[i];
    }
    int l = 1,r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check1(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return;
}
signed main(){
    //ios::sync_with_stdio(false),cin.tie(nullptr);
    //*
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //*/
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}
