#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], p[500005];
int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int k = a[1];
    for (int i=1; i<=n; i++){
        a[i] -= k;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<i; j++){
            p[i] += a[i] - a[j];
        }
    }
    int total = 0;
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (total < j-i+1 && (p[j] - p[i-1]) <= m){
                total = j-i+1;
           //     cout << i << ' ' << j << endl;
            }
        }
    }
    cout << total;
    return 0;
}
//0 1 3 7 8
//0 1
