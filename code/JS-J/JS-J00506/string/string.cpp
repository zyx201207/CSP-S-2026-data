#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long len, ans;

struct s
{
    unsigned long long start;
    int a;
    char c;
};

vector<s> str;

char getch(unsigned long long p)
{
    int i = 0;
    unsigned long long sum = 0;
    while (sum < p)
    {
        sum += str[i++].a;
    }
    return str[i - 1].c;
}

int geti(unsigned long long p)
{
    int i = 0;
    unsigned long long sum = 0;
    while (sum < p)
    {
        sum += str[i++].a;
    }
    return i - 1;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        str.push_back({len, a, c});
        len += a;
    }
    //printf("len=%lld\n", len);
    unsigned long long i = 1;
    while (i < (len + 1) / 2)
    {
        //printf("loop i=%lld\n", i);
        if (getch(i) != getch(len - i + 1))
        {
            //cout << geti(i) << endl;
            auto l = str[geti(i)];
            auto r = str[geti(len - i + 1)];
            unsigned long long left = l.start + l.a - i + 1;
            unsigned long long right = len - i + 1 - r.start;
            //printf("l=%d r=%d\n", left, right);
            if (left > right)
            {
                //printf("shipei pos=%lld jump by %d ans=%lld\n", i, right, ans + right);
                ans += right;
                i += right;
            }
            else
            {
                //printf("shipei pos=%lld jump by %d ans=%lld\n", i, left, ans + left);
                ans += left;
                i += left;
            }
        }
        else
        {
            //printf("ok pos=%lld jump by %d ans=%lld\n", i, 1, ans);
            auto l = str[geti(i)];
            auto r = str[geti(len - i + 1)];
            unsigned long long left = l.start + l.a - i + 1;
            unsigned long long right = len - i + 1 - r.start;
            if (left > right)
            {
                i += right;
            }
            else
            {
                i += left;
            }
        }
    }

    // cout << (getch(1) == getch(len - 1 + 1) ? 1 : 0) << endl;
    // for (unsigned long long i = 1; i < (len + 1) / 2; i++)
    // {
    //     ans += !(getch(i) == getch(len - i + 1));
    // }
    cout << ans << endl;

    // unsigned long long x;
    // while (cin >> x)
    //     cout << geti(x) << endl
    //          << str[geti(x)].a << endl;
    //6 1000000000 a  1000000000 a  1000000000 a  1000000000 b  1000000000 b  1000000000 b
}