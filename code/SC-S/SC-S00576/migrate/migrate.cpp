#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 5;
int n;
ll d,a[N];
void solve1(){
    cout <<"0\n";
}
void solve2(ll cha){
    ll ans = 0;
    if (cha * 2 > d || cha * 3 < d) cout <<"0\n";
    else cout <<n - 3 <<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >>c >>t;
    while (t--){
        cin >>n >>d;
        ll cha;
        bool f = 1;
        for (int i = 1; i <= n; i++){
            scanf("%lld",&a[i]);
            if (i == 2) cha = a[i] - a[i - 1];
            else{
                if (a[i] - a[i - 1] != cha && i != 1) f = 0;
            }
        }
        if (f) solve2(cha);
        else solve1();
    }
    return 0;
}
