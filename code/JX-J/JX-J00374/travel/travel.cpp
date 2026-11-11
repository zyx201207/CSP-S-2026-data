#include <bits/stdc++.h>
using namespace std;

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

int c1, c2;
string s1, s2, result;

int main()
{
    freopen("travel.in", "r", stdin);

    #ifndef _DEBUG
        freopen("travel.out", "w", stdout);
    #endif // _DEBUG

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    result.resize(4);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) result[0] = '1';
    else result[0] = '0';

    if (s1.substr(0, 2) == s2.substr(0, 2)) result[1] = '1';
    else result[1] = '0';

    // true: left, false: right
    bool s1_s = ((s1[2] >= 'A' && s1[2] <= 'C') ? true : false);
    bool s2_s = ((s2[2] >= 'A' && s2[2] <= 'C') ? true : false);
    MSG("1 = left, 2 = right");
    LOG(s1_s);
    LOG(s2_s);

    if (s1_s == s2_s) result[2] = '1';
    else result[2] = '0';

    if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1) result[3] = '1';
    else result[3] = '0';

    OUT(result);
}
