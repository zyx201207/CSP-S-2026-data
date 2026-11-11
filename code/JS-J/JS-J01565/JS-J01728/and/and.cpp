#include <bits/stdc++.h>
using namespace std;
int n,m,nums[300000],dp[300000][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);



    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> nums[i];
        dp[i][1] = nums[i];
    }
    //cout << "\033[2;48;2;78;91;13;38;2;255;78;89m";
    for(int i = 2;i <= m;i++)
    {
        if (i == 3)for(int j = 0;j < n;j++) dp[j][1] = 0;
        for(int j = 1;j <= n;j++)
        {
            dp[j][i&1] = dp[j-1][i&1];
            for(int k = 1;k < j;++k)
            {
                //cout << dp[j][i&1] << "->";
                dp[j][i&1] = max(dp[j-k][(i-1)&1]&nums[j],dp[j][i&1]);

            }
            //cout << dp[j][i&1] << ' ';
        }
        //cout << '\n';
    }
    //cout << "\033[0m\n";

    for(int i = 1;i <= n;i++) dp[0][0] = max(dp[0][0],dp[i][m&1]);
    cout << dp[0][0];
    return 0;
}
