#include<iostream>
#include<vector>
using namespace std;
vector<pair<long long, char> > a;
long long dp[200001][200001];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        int x;
        char y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for(int i = 1;i < int(a.size());i ++)
    {
        if(a[i].second == a[i - 1].second)
        {
            a[i - 1].first += a[i].first;
            a.erase(a.begin() + i);
            i --;
        }
    }
    n = a.size() - 1;
    for(int len = 2;len <= n;len ++)
    {
        for(int i = 0;i <= n - len + 1;i ++)
        {
            int j = i + len - 1;
            dp[i][j] = 200000000000001ll;
            if(a[i].second == a[j].second)
            {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + abs(a[i].first - a[j].second));
            }
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[i].first);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[j].first);
        }
    }
    cout << dp[1][n];
}
/*
cin1:

cout1:

cin2:

cout2:

cin3:

cout3:

cin4:

cout4:

cin5:

cout5:

*/
