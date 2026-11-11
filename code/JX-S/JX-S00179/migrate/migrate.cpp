#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int c, t;
int n;
ll d;
const int N = 2e6 + 5;
ll a[N];
int query(ll r){//count <= r
    int ind = upper_bound(a + 1, a + n + 1, r) - a - 1;
    return ind;
}
int query(ll l, ll r){// count (l, r)
    return query(r) - query(l - 1);
}
ll dp[N][2], la[N];//0: no b_i < a_i  1: have a b_i < a_i
int to[N], cnt[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            dp[i][0] = dp[i][1] = la[i] = 0;
            to[i] = cnt[i] = 0;
        }
        for(int i = 1;i <= n;i++){
            to[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            cnt[i] = to[i] - i;
        }
        ll ans = 0;
        for(int i = n;i >= 1;i--){
            if(!cnt[i]){//can't to any place
                dp[i][0] = dp[i][1] = 0;
            }else{
                dp[i][0] = dp[to[i]][0], dp[i][1] = dp[to[i]][1];
//                cout << "cnt::" << cnt[i] << ' ' << cnt[to[i]] << ' ' << to[i] << '\n';
                if(cnt[i] > 1 && cnt[to[i]]){
                    if(a[to[i] - 1] + d >= a[to[to[i]]]){//i -> to[i] - 1 -> to[to[i]]
                        if(cnt[i] > 2 && a[to[i] - 2] + d >= a[to[to[i]]]){
                            dp[i][1] = dp[i][0] = 0;
                        }else{// dp : from to[to[i]] = 0
                            la[i] = dp[i][1] = dp[i][0] - (cnt[i] > 2 ? query(a[to[i]] + 1, a[to[i] - 2] + d) : 0);
                            dp[i][0] = 0;
                        }
                    }else{
                        if(la[to[i]] && a[to[i] - 1] + d >= a[to[to[i]] - 1]){
                            dp[i][1] -= la[to[i]];
                        }
                        int ccc = query(a[to[i]] + 1, a[to[i] - 1] + d);
                        if(cnt[i] > 1) ccc -= query(a[to[i]] + 1, a[to[i] - 2] + d);
                        dp[i][0] -= ccc, dp[i][1] += ccc, la[i] = ccc;
                    }
                }
                dp[i][0] += cnt[i];//i + 1 ~ to[i] len = 1   only 1!
            }
            ans += dp[i][1];
//            cerr << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
/*
gan jue jia wan le
wo shi qv wang
wo zen me shen me dou bu hui zuo
/bx lw393 /bx Mr_min /bx gmh123456gmh /bx 1??????????a /bx xzy_ak_ioi /bx tooolazy /bx szh_ak_all /bx infter(inftress?) /bx zhoumurui
/bx system32 /bx deepthinker? /bx... sheng xia de wang ji le qwq wo shi qv





qwq zuo le 2h jia diao le
beng kui le


aaaaaaaaaaaaaa di 5 ge yang li guo bu qv , di 6 ge guo de qv
*/
