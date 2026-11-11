#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
bool book[MAXN];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        book[i] = true;
    }
    for (int k = 29;k >= 0;k--){
        int num = 0;
        for (int i = 1;i <= n;i++){
            if (book[i]){
                if (a[i] & (1 << k)){
                    num++;
                }
            }
        }
        if (num >= m){
            ans += (1 << k);
            for (int i = 1;i <= n;i++){
                if (book[i]){
                    if ((a[i] & (1 << k)) == 0){
                        book[i] = false;
                    }
                }
            }
        }
    }
    cout << ans;
}
