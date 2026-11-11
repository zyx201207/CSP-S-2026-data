#include <bits/stdc++.h>
using namespace std;
const int NR = 500100;

long long a[NR], s[NR];
int n, delt;
long long m;
bool sp = true;
bool check(int x){
    return (1ll * x * a[x] - s[x]) <= m;
}

int solve(){
    int l = 1, r = n;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i == 2) delt = abs(a[i] - a[i - 1]);
        if ((i >= 3) && (abs(a[i] - a[i - 1]) != delt)){
            sp = false;
        }
    }
    if (sp == true && delt != 0){
        for (int i = 1; i <= n; i++){
            s[i] = s[i - 1] + i;
            if ((s[i] < 0 && s[i - 1] > 0) || (s[i] > 1ll * m / delt)){
                cout << i;
                return 0;
            }

        }
    }else if (sp == true){
        cout << n;
        return 0;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }

    long long ans = -1, ud = 0;
    int l = 1, r = 1;
    while (r <= n){
        cout << l << ' ' << r << '\n';
        if (1ll * ud + (1ll * r - l + 1) * (a[r + 1] - a[r]) <= m){
            r++;
            if (r > n) break;
            ud += (1ll * r - l + 1) * (a[r + 1] - a[r]);
            ans = max(ans, 1ll * r - l + 1);
        }else {
            l++;
            if (l > n) break;
            ud -= (a[r] - a[l]);
            cout << ud << '\n';
        }
    }
    cout << ans;
}


// 题目名字belike: Xterfusion | X X XXX