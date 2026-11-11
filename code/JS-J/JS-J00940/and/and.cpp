#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    freopen("and.in", "r", stdin);

    freopen("and.out", "w", stdout);

    int n, m;

    long long sum = 0, maxsum = 0;

    cin >> n >> m;

    vector<long long> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    sum = a[n - 1];

    maxsum = sum;

    for (int i = 0; i < m; i++){
        for (int j = n - 1; j >= 0; j--){
            if (sum & a[j] > maxsum){
                maxsum = sum & a[j];
            }
        }
        sum = maxsum;
        maxsum = 0;
        n--;
    }

    cout << sum;

    return 0;
}
