#include<bits/stdc++.h>

using namespace std;

struct node
{
    int len;
    char c;
};
node a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        a[i].len = x;
        a[i].c = c;
    }

    long long L = 1, R = n, l = a[L].len, r = a[R].len, ans = 0;
    while(L <= R)
    {
        if(a[L].c == a[R].c)
        {
            if(l > r)
            {
                l -= r;
                R--;
                r = a[R].len;
            }
            else
            {
                r -= l;
                L++;
                l = a[L].len;
            }
        }
        else
        {
            if(l > r)
            {
                ans += r;
                l -= r;
                R--;
                r = a[R].len;
            }
            else
            {
                ans += l;
                r -= l;
                L++;
                l = a[L].len;
            }
        }
    }
    cout << ans;
    return 0;
}
