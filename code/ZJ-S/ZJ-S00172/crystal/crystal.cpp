#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;

int lst[N] = {};

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i=0;i<n;i++) scanf("%lli", &lst[i]);
    sort(lst, lst+n);

    int sum = 0;
    int maxn = 0;
    int fr = 0; 
    // fr 维护前指针，i 维护后指针
    for (int i=0;i<n;i++) {
        sum += (lst[i]-lst[i-1])*(i-fr);
        if (sum > m) {
            // 抛掉后面的指针
            while(sum > m) {
                sum -= lst[i] - lst[fr];
                fr++;
            }
        }
        maxn = max(maxn, i-fr+1);
    }

    printf("%lli", maxn);

    return 0;    
}
