#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
long long n, m, a[MAXN], ans;
map <long long, long long> cnt;

void dfs(int step, int rest){
    if (step > n){
        cnt.clear();
        for (int i = 1; i <= n; i++){
            cnt[a[i]]++;
        }
        for (auto p: cnt){
            ans = max(ans, p.second);
        }
        return ;
    }
    if (rest == 0){
        dfs(n+1, 0);
        return ;
    }
    if (rest < 0){
        return ;
    }
    for (int i = 0; i <= rest; i++){
        a[step] += i;
        dfs(step+1, rest-i);
        a[step] -= i;
    }
}

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
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
    }
    dfs(1, m);
    printf("%d", ans);
}