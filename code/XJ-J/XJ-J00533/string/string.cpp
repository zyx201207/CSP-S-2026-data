#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e5 + 5;
int n, ans;
struct str{
    int left, right;
    char ch;
}s[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        s[i].left = s[i - 1].right + 1;
        s[i].right = s[i - 1].right + a;
        s[i].ch = c;
    }
    // for(int i = 1; i <= n; i++)
    //     cout << s[i].left << " " << s[i].right << " " << s[i].ch << endl;
    str h = s[1], t = s[n];
    for (int l = 1, r = n; l <= r;)
    {
        if (h.right - h.left == t.right - t.left)
        {
            ans += (h.right - h.left + 1) * (h.ch != t.ch);
            l++, r--;
            h = s[l];
            t = s[r];
        }
        else if (h.right - h.left > t.right - t.left)
        {
            ans += (t.right - t.left + 1) * (h.ch != t.ch);
            r--;
            h.left += t.right - t.left + 1;
            t = s[r];
        }
        else if (h.right - h.left < t.right - t.left)
        {
            ans += (h.right - h.left + 1) * (h.ch != t.ch);
            l++;
            t.right -= h.right - h.left + 1;
            h = s[l];
        }
	}
    cout << ans;
    return 0;
}
