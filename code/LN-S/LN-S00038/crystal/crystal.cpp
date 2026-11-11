#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 +10;
int n, m;
long long a[maxn];
long long b[maxn];//前缀和数组
int check(int mid) {//最多的操作数
    long long t = a[mid];
    int l = 1, r = mid;
    int ans = 0;
    while(l <= r) {//枚举个数
        int midd = (l + r + 1) / 2;
        if(midd * t - (b[mid - 1] - b[mid - midd - 1]) <= m)
            l = midd + 1, ans = midd;
        else
            r = midd - 1;
    }
    return ans + 1;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    b[0] = 0;
    for(int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, check(i));
    cout << ans;
    return 0;
}
