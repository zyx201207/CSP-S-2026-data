#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff(i, l, r) for(int i = (l), END##i = (r); i < END##i; ++i)
#define ffe(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r) for(int i = (l), END##i = (r); i > END##i; --i)
#define fbe(i, l, r) for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v) for(auto &it : v)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int n, a[500002], ans = 1; ll m;
int main()
{
	//IOS;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ffe(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	ll s = 0;
    while(l <= r && r <= n)
    {
        if(a[r] != a[r - 1])
            s = s + (r - l) * (a[r] - a[r - 1]);
        while(s > m) s -= (a[r] - a[l - 1]), ++l;
        ans = max(ans, r - l + 1);
        //cout << r << ' ' << s << '\n';
        r++;
    }
    cout << ans;
	return 0;
}
