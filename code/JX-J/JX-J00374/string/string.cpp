#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

// #define _DEBUG
#define endl '\n'

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#ifdef _DEBUG
    #define LOG(var) cerr << TOSTRING(var) " = " << var << endl
    #define MSG(msg) cerr << msg << endl
    #define OUT(expr) cerr << expr << endl
#else
    #define LOG(var)
    #define MSG(msg)
    #define OUT(expr) cout << expr << endl
#endif // _DEBUG

string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    char c;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> m >> c;
        s.append(string(m, c));
    }

    LOG(s);
    u64 mid, sz = s.size();
    bool is;
    if (sz % 2 == 0)
    {
        MSG("sz % 2 == 0");
        mid = sz / 2;
        is = true;
    }
    else
    {
        MSG("sz % 2 == 1");
        mid = sz / 2;
        is = false;
    }

    u64 lcnt = 0, rcnt = 0;
    string left = s.substr(0, mid);
    string right;
    if (is) right = s.substr(mid);
    else right = s.substr(mid + 1);
    string needl = left;
    string needr = right;
    reverse(needl.begin(), needl.end());
    reverse(needr.begin(), needr.end());

    LOG(left);
    LOG(right);
    LOG(needl);
    LOG(needr);
    LOG(mid);

    for (u64 i = 0; i < mid; ++i)
    {
        if (right[i] != needl[i])
        {
            lcnt++;
        }
        if (left[i] != needr[i])
        {
            rcnt++;
        }
    }

    OUT(min(lcnt, rcnt));
}




























