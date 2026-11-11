#include <bits/stdc++.h>
using namespace std;
template <typename T>
long long check(vector<pair<long long, T>> v1, vector<pair<long long, T>> v2)
{
    long long d = 0;
    for (long long i = 0, j = 0; i < v1.size() && j < v2.size();)
    {
        auto &a = v1[i], &b = v2[j];
        if (a.first == 0)
        {
            i++;
            continue;
        }
        if (b.first == 0)
        {
            j++;
            continue;
        }
        if (a.first > b.first)
        {
            if (a.second != b.second)
            {
                d += b.first;
            }
            a.first -= b.first;
            j++;
        }
        else if (a.first < b.first)
        {
            if (a.second != b.second)
            {
                d += a.first;
            }
            b.first -= a.first;
            i++;
        }
        else
        {
            if (a.second != b.second)
            {
                d += b.first;
            }
            i++;
            j++;
        }
    }
    return d;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    long long n;
    cin >> n;
    long long len = 0;
    vector<pair<long long, char>> a;
    for (long long i = 0; i < n; i++)
    {
        long long l;
        char ch;
        cin >> l >> ch;
        a.push_back({l, ch});
        len += l;
    }
    if (len & 1)
    {
        long long f = ((len + 1) >> 1) - 1;
        long long now = 0;
        vector<pair<long long, char>> h;
        long long i;
        for (i = 0; i < n; i++)
        {
            if (now + a[i].first > f)
                break;
            h.push_back(a[i]);
            now += a[i].first;
        }
        if (f - now)
            h.push_back({f - now, a[i].second});
        auto t = vector<pair<long long, char>>(h.rbegin(), h.rend());
        h.push_back({1, a[i].second});
        h.insert(h.end(), t.begin(), t.end());
        cout << check(a, h);
    }
    else
    {
        long long f = len >> 1;
        long long now = 0;
        vector<pair<long long, char>> h;
        long long i;
        for (i = 0; i < n; i++)
        {
            if (now + a[i].first > f)
                break;
            h.push_back(a[i]);
            now += a[i].first;
        }
        auto t = vector<pair<long long, char>>(h.rbegin(), h.rend());
        if (f - now)
            h.push_back({f - now, a[i].second});
        h.insert(h.end(), t.begin(), t.end());
        cout << check(a, h);
    }
}