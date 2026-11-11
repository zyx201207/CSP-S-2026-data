#include <iostream>
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int a[MAXN], f[MAXN], nxt[MAXN], fir[MAXM];
long long cnt[MAXM];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        f[i] = 1;
    }
    for (int i = n;i >= 1;i--){
        if (!fir[a[i]]){
            fir[a[i]] = i;
        }
        nxt[i] = fir[a[i]] + 1;
    }
    for (int i = 1;i <= n;i++){
        cnt[a[i]] += f[i];
        f[nxt[i]] += f[i];
    }
    for (int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
}
