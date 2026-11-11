#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

const int MAXN = 2e6 + 5;

long long n, k, a[MAXN];
long long num;
string s;
char c[MAXN];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    buff;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        num += a[i];
    }

    long long l = 1, r = n - 1, ans = 0;
    while (l < r)
    {
        if (c[l] == c[r])
        {
            if (a[l] < a[r])
            {
                l++;
                a[r] -= a[l];
            }
            else if (a[l] > a[r])
            {
                r--;
                a[l] -= a[r];
            }
            else if (a[l] == a[r])
            {
                l++;
                r--;
            }
        }
        else
        {
            if (a[l] < a[r])
            {
                l++;
                a[r] -= a[l];
                ans += a[l];
            }
            else if (a[l] > a[r])
            {
                r--;
                a[l] -= a[r];
                ans += a[r];
            }
            else if (a[l] == a[r])
            {
                l++;
                r--;
                ans += a[l];
            }
        }
    }
    cout << ans;
    return 0;
}
