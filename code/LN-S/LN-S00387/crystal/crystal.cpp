#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;

ll n, m, ans = 1;
ll a[N], sp[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += 100000;
    }
    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i++){
        sp[i] = sp[i-1] + a[i];
    }

    //for (int i = 1; i <= n; i++)    cout << a[i] << ' ';
    //cout << endl;

    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            ll sum = sp[j] - sp[i-1];
            ll mid = sum / (j - i + 1);
            //cout << i << ' ' << j << ' ' << sum << ' ' << mid << ' ';
            ll c = 0;
            bool ok = 1;
            //cout << "c:";
            for (int k = i; k <= j; k++){
                c += abs(mid - a[k]);
                //cout << c << ' ';
                if (c > m){
                    ok = 0;
                    break;
                }
            }
            //cout << c << '\n';
            if (ok) ans = max(ans, (ll)(j - i + 1));
        }
    }

    cout << ans << '\n';

    return 0;
}


/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
