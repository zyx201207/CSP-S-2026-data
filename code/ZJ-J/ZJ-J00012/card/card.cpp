#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;
const int MAXM = 3e5+10;
int n, m, a[MAXN], cur[MAXN], l, r, ans[MAXM];

int read(){
    int sum = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-'){
            sign = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        sum = (sum << 1)+(sum << 3)+(ch ^ 48);
        ch = getchar();
    }
    return sum*sign;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
    }
    for (int i = 1; i <= n; i++){
        l = 1;
        r = 1;
        cur[l] = a[i];
        for (int j = i+1; j <= n; j++){
            int val = a[j];
            for (int k = l; k <= r; k++){
                if (cur[k] == val){
                    r = k-1;
                    break;
                }
            }
            cur[++r] = val;
        }
        for (int j = l; j <= r; j++){
            ans[cur[j]]++;
        }
    }
    for (int i = 1; i <= m; i++){
        printf("%d ", ans[i]);
    }
}