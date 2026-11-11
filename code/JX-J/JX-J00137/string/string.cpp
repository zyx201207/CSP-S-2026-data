#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	cin >> n;
	vector <pair <long long, char>> vec(n + 10);
	for (auto i = 0; i < n; ++i)
        cin >> vec[i].first >> vec[i].second;
    long long i = 0, j = n - 1, cnt = 0;
    while (j - i > 0)
    {
        if (vec[i].first == vec[j].first && vec[i].second == vec[j].second)
        {
            ++i;
            --j;
            continue;
        }
        auto &ni = vec[i].first >= vec[j].first? vec[i].first: vec[j].first, &nj = vec[i].first <= vec[j].first? vec[i].first: vec[j].first;
        if (vec[i].second != vec[j].second)
            cnt += nj;
        ni -= nj;
        if (!vec[i].first)
            ++i;
        if (!vec[j].first)
            --j;
        nj = 0;
    }
    cout << cnt << '\n';
	/* auto sum = 0LL;
	while (n--)
    {
        int ai;
        char ci;
        cin >> ai >> ci;
        str += string(ai, ci);
        sum += ai;
    }
    auto cnt = 0LL;
    for (auto i = 0LL; i < sum / 2; ++i)
        cnt += str[i] != str[sum - i - 1];
    cout << cnt << '\n'; */
	return 0;
}
