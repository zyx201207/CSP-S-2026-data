#include <iostream>
using namespace std;
int maxN = 2*100000 + 1;
int a[maxN];
int dp[maxN][maxN];
int main()
{
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/and/and.in","r",stdin);
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/and/and.out","r",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a+n + 1);
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j],dp[i-1][j-1] & a[j]);
        }
    }
    cout << dp[m][n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
