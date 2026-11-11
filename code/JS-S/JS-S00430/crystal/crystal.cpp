#include <bits/stdc++.h>
#define ll long long int
#define fi first
#define se second
#define rep(i, f, t) for(int i = f ; i <= t ; ++i)
#define per(i, f, t) for(int i = f ; i >= t ; --i)
#define all(x) x.begin() x.end()
#define re return
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tupii pair<int, pii>
#define t1 fi
#define t2 se.fi
#define t3 se.se

using namespace std;
ll n, m, a[500007], res, f = 1, v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    rep(i, 1, n)cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 2, n){
        v += (i - f) * (a[i] - a[i - 1]);
        while(v > m){
            v-=(a[i] - a[f]);
            f++;
        }
        res = max(res, i - f + 1);
    }
    cout << res;
    re 0;
}
/*
I'm gonna b the first guy who wears Genshin Columnbina series gear in noi series LOL
without using cpp 4 a <del>log n</del> long time, forgot to "int a;" first
before seeing the tests,I've drank all my drinks out:(
Aiiii,you4 shi4 lei4 hun2


5min files preparing
15min computer doesnt work
30min t1
90min computer doesnt work again(tanqi ai youshileihun)
120min again :)
130min again and change a computer
*/
