//dp[i]表示以i结尾的按位与最大值
#include<bits/stdc++.h>
using namespace std;

#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
const int N = 2005;
int a[N], dp[N][N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n = read(),m=read();
    for(int i  =1; i<=n; i++){
        a[i]=read();
        dp[i][1] = a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            for(int k = m; k >= 1; k--){
                dp[i][k] = max(dp[i][k], dp[j][k-1]&a[i]);
            }
        }
    }
    int maxn = -1e9;
    for(int i = 1;  i <= n; i++)maxn = max(maxn, dp[i][m]);
    printf("%lld",maxn);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

