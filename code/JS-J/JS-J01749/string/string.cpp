#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<long long, char>> A;
    long long L = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        if (!A.empty() && c == A.back().second)
        {
            A.back().first += a;
        }
        else
        {
            A.push_back(make_pair(a, c));
        }
        L += a;
    }
    deque<pair<long long, char>> Q;
    long long mid = L / 2;
    long long l = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (L % 2 && l + A[i].first > mid)
        {
            A[i].first--;
        }
        if (l + A[i].first == mid)
        {
            for (int j = i; j < A.size(); j++)
            {
                Q.emplace_back(A[j]);
            }
            break;
        }
        if (l + A[i].first > mid)
        {
            Q.push_back(make_pair(mid - l, A[i].second));
            Q.push_back(make_pair(A[i].first - (mid - l), A[i].second));
            for (int j = i + 1; j < A.size(); j++)
            {
                Q.emplace_back(A[j]);
            }
            break;
        }
        Q.emplace_back(A[i]);
        l += A[i].first;
    }
    long long ans = 0;
    while (Q.size())
    {
        if (Q.front().second != Q.back().second)
        {
            ans += min(Q.front().first, Q.back().first);
        }
        if (Q.front().first < Q.back().first)
        {
            Q.back().first -= Q.front().first;
            Q.pop_front();
        }
        else if (Q.front().first > Q.back().first)
        {
            Q.front().first -= Q.back().first;
            Q.pop_back();
        }
        else
        {
            Q.pop_back();
            if(Q.size())
                Q.pop_front();
        }
    }
    cout << ans << endl;
    return 0;
}
