#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    long long t;
    long long max_num = -1;
    cin >> n >> m;
    if (m == 1){
        for (long long i = 1; i <= n; i ++){
            cin >> t;
            if (t > max_num){
                max_num = t;
            }
        }
        cout << max_num << endl;
        return 0;
    }
    if (m == n){
        cin >> t;
        long long sum = t;
        for (long long i = 1; i < n; i ++){
            cin >> t;
            sum &= t;
        }
        cout << sum << endl;
        return 0;
    }
}
