#include<bits/stdc++.h>
using namespace std;
int in = 0, n, dp[20005][20005], a[200005];
char c;
string s, b;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i]>>c;
        for (int j = 1;j<=a[i];j++){
            in++;
            s[in] = c;
        }
    }
    int temp = in;
    for (int i = 1;i<=in;i++){
        b[temp] = s[i];
        temp--;
    }
    for(int i = 0;i<=in;i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1;i<=in;i++){
        for (int j = 1;j<=i;j++){
            if (s[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout<<dp[in][in];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
