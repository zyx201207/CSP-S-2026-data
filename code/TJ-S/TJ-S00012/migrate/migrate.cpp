#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff(i, l, r) for(int i = (l), END##i = (r); i < END##i; ++i)
#define ffe(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r) for(int i = (l), END##i = (r); i > END##i; --i)
#define fbe(i, l, r) for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v) for(auto &it : v)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll T, n, a[2000002], f[2000002], q[2000002], d;
map<ll,int> mp;
int main()
{
//	IOS;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> T >> T;
    while(T--)
    {
        cin >> n >> d;
        ffe(i, 1, n) cin >> a[i];
        ++n, a[n] = a[n - 1] + d;
        int hd = 1, tl = 0;
        ll s = 0;
        ffe(i, 1, n)
        {
            while(hd <= tl && a[i] - a[q[hd]] > d) --mp[f[q[hd]]], ++hd;
            f[i] = f[q[hd]] + 1;
            while(hd <= tl && f[q[tl]] > f[i]) --mp[f[q[tl]]], --tl;
            ++tl, q[tl] = i, ++mp[f[i]];
            //upper_bound(q2 + hd - 1, q2 + 1 + tl, f[i] - 1) - q2 - hd;// - lower_bound(q2 + hd - 1, q2 + 1 + tl, f[i]);
            s += (mp[f[i] - 1] == 2);
            //cout << s << '\n';
            //ffe(i, hd, tl) cout << q2[i] << ' '; cout << " : " << f[i] << ' ' << k << ' ' << '\n';
        }
        //ffe(i, 1, n) cout << f[i] << ' '; cout << '\n';
        cout << s << '\n';
        //cout << '\n';
    }
	return 0;
}
