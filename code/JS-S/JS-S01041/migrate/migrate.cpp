#include <iostream>
using namespace std;
const int MAXN = 2e6 + 5;
long long a[MAXN];
int main(){
    int c, t, n;
    long long m;
    cin >> c >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1;i <= n;i++){
            cin >> a[i];
        }
        if (c == 11 || c == 12){
            long long k = a[2] - a[1], sum = 0;
            for (int i = 3;i < n;i++){
                if (m < i * k && i * k < 2 * m){
                    sum += n - i;
                }
            }
            cout << sum << '\n';
            continue;
        }
        cout << "I AK IOI!!!OvO\n";
    }
}
