#include <iostream>

using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int n;
ll ans, s;
char a[N];
ll d[N];

void init(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;

}

void solve(){
    for(int i = 1; i <= n; ++i)
        cin >> d[i] >> a[i];
    for(int i = 1; i <= n / 2; ++i){
        if(a[i] != a[n - i + 1]){
            if(d[i] + s <= d[n - i + 1]){
                ans += d[i] + s;
                s = d[n - i + 1] - d[i] - s;
            } else {
                ans += d[n - i + 1];
                s = d[i] + s - d[n - i + 1];
            }
        }
    }
    ans += s;
    cout << ans << endl;
}

int main(){
    init();
    solve();
    return 0;
}
