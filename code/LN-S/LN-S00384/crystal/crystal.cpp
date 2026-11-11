#include<bits/stdc++.h>
using namespace std;
long long a[200000] = {};
long long k[200000] = {};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n = 0,m = 0;
    cin >> n >> m;
    for(long long i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (long long i = 1 ; i < n ; i++) {
        for (long long j = i + 1 ; j <= n ; j++) {
            if (a[i] > a[j]) {
                swap(a[i],a[j]);
            }
        }
    }
    for (long long i = 1 ; i < n ; i++) {
        k[i] = a[i + 1] - a[i];
    }
    long long mini = 1000000000000;
    for (int i = 1 ; i < n -1 ; ; i++) {
        long long k1 = k[i] + k[i + 1];
        long long k2 = k[i + 1] + k[i + 2];
        if (k1 < k2) {
            mini = i;
        }
    }
    long long cnt = 0;
    for (long long i = mini ; i < n ; i++) {
        int b = a[i] - a[i + 1]
        if (b <= m) {
            cnt++;
            m -= b;
        }
    }
    cout  << cnt << endl;
    return 0;
}

