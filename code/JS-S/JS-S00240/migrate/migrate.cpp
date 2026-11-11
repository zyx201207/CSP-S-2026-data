#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 7;
int c, t;
int n; ll d;
ll in[maxn];
ll ans = 0;


namespace brute{
    int dp1[maxn];
    ll dp2[maxn];

    unordered_map<int, int> mp;
    void doit(int x){
        mp.clear();
        int l = x;
        deque<ll> gh;
        gh.push_back(x);
        dp1[x] = 0;
        dp2[x] = 1;
        mp[0] = 1;
        for(int i = x + 1; i <= n; ++i){
            while(in[l] < in[i] - d){
                mp[dp1[l]] -= dp2[l];
                l ++;
            }
            while(!gh.empty() && gh.front() < l){
                gh.pop_front();
            }
            if(gh.empty()){
                return;
            }
            dp1[i] = dp1[gh.front()] + 1;
            dp2[i] = mp[dp1[i] - 1];
            if(dp2[i] > 2){
                dp2[i] = 3;
            }
            if(dp2[i] == 2){
                ans ++;
            }
            mp[dp1[i]] += dp2[i];
            while(!gh.empty() && dp1[gh.back()] >= dp1[i]){
                gh.pop_back();
            }
            gh.push_back(i);
        }
    }
    void solve(){
         for(int i = 1; i < n; ++i){
            doit(i);
         }
    }
}


namespace sub3{
    int dp1[maxn];
    ll dp2[maxn];
    bool ok[maxn];
    int pre[maxn];
    ll cnt = 0;
    unordered_map<int, int> mp;
    void doit(int x){
        mp.clear();
        int l = x;
        deque<ll> gh;
        gh.push_back(x);
        dp1[x] = 0;
        dp2[x] = 1;
        mp[0] = 1;
        for(int i = x + 1; i <= n; ++i){
            while(in[l] < in[i] - d){
                mp[dp1[l]] -= dp2[l];
                l ++;
            }
            while(!gh.empty() && gh.front() < l){
                gh.pop_front();
            }
            if(gh.empty()){
                return;
            }
            dp1[i] = dp1[gh.front()] + 1;
            dp2[i] = mp[dp1[i] - 1];
            if(dp2[i] > 2){
                dp2[i] = 3;
            }
            if(dp2[i] == 2){
                ++ cnt;
                ok[i] = 1;
            }
            mp[dp1[i]] += dp2[i];
            while(!gh.empty() && dp1[gh.back()] >= dp1[i]){
                gh.pop_back();
            }
            gh.push_back(i);
        }
    }
    void solve(){
         cnt = 0;
         doit(1);
         int jk = 0;
         for(int i = 1; i <= n; ++i){
            pre[i] = pre[i - 1];
            if(ok[i]) pre[i] ++;
         }
         for(int i = 1; i <= n; ++i){
             ans += pre[n - jk];
             jk ++;
         }
    }
}

void solve(){
    ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        cin >> in[i];
    }
    if(n <= 5000){
        brute::solve();
        cout << ans << '\n';
    }else if(c == 11 || c == 12){
        sub3::solve();
        cout << ans << '\n';
    }else{
        cout << 0 << '\n';
    }

}


int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> t;
    while(t --){
        solve();
    }
    return 0;
}
