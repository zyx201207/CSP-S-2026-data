#include<bits/stdc++.h>
using namespace std;
using itn = int;
using ll = int64_t;
#define endl '\n'
#define file "crystal"
int main(void)
{
    #ifndef NO_FREOPEN
    (void)!freopen(file ".in", "r", stdin);
    (void)!freopen(file ".out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<ll> vec;
    int n, i, j; ll a, m;
    cin >> n >> m;
    for (i=0; i<n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    ll tot = 0;
    for (i=j=0; i<n; i++)
    {
        if (i) tot += (i-j) * (vec[i]-vec[i-1]);
        while (tot > m) tot -= vec[i] - vec[j++];
        ans = max(ans, i-j+1);
    }
    cout << ans << endl;
}
