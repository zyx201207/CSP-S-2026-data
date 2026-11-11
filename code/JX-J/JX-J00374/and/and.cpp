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

int sumof(uint32_t a)
{
    int sum = 0;
    while (a)
    {
        if ((1u & a) != 0) sum++;
        a >>= 1;
    }
    return sum;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), [](int a, int b) { return a > b; });

    #ifdef _DEBUG
        for (const auto i : a)
        {
            LOG(i);
        }
    #endif // _DEBUG

    u64 result = *(a.begin());
    for (u64 i = 1; i < m; ++i)
    {
        result &= a[i];
    }


    OUT(result);
}
























