#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

//#define _DEBUG
#define endl '\n'

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#ifdef _DEBUG
    #define LOG(var) cerr << TOSTRING(var) " = " << var << endl
    #define MSG(msg) cerr << msg << endl
    #define OUT(expr) cerr << expr
#else
    #define LOG(var)
    #define MSG(msg)
    #define OUT(expr) cout << expr
#endif // _DEBUG

vector<int> cards, games;

pair<u64, bool> where(const vector<int>& vec, int n)
{
    u64 pos = 0;
    for (const auto it : vec)
    {
        if (it == n)
        {
            return { pos, true };
        }
        pos++;
    }
    return { 0, false };
}

#ifdef _DEBUG
void printvec(const vector<int>& vec)
{
    cerr << '[';
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cerr << *it << ", ";
    }
    cerr << ']' << endl;
}
#else
#define printvec(vec)
#endif // _DEBUG

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    cards.reserve(n);
    games.resize(m);
    i64 round = 1;

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }

    while (round <= n)
    {
        vector<int> desktop;
        desktop.reserve(n);

        for (u64 i = round - 1; i < n; ++i)
        {
            auto r = where(desktop, cards[i]);
            if (r.second)
            {
                desktop.erase(desktop.begin() + r.first, desktop.end());
                printvec(desktop);
            }
            desktop.push_back(cards[i]);
            printvec(desktop);
        }

        for (u64 i = 0; i < desktop.size(); ++i)
        {
            LOG(desktop[i]);
            games[desktop[i] - 1] += 1;
        }
        round++;
    }

    for (const auto it : games)
    {
        OUT(it << ' ');
    }
    OUT(endl);
}












