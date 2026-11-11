#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 +5;
int n, m, cnt, ans;
int a[N], b[32];
bool fl;
bitset<22> zw;
int t[5];
void dfs(bitset<22>f, int dep, int num, int val){
    if(num == m){
        ans = max(ans, val);
        return;
    }
    if(dep > n) return;
    f[dep] = 1;
    if(num == 0) dfs(f, dep + 1, 1, a[dep]);
    else dfs(f, dep + 1, num + 1, val & a[dep]);
    f[dep] = 0;
    dfs(f, dep + 1, num, val);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == i - 1) cnt++;
        if(a[i] > 4) fl = true;
    }
    if(n <= 20) dfs(zw, 0, 0, 0);
    else if(n <= 2000){
        if(m == 1)
            for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
        if(m == 2){
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    ans = max(ans, a[i] & a[j]);
        }
        if(m == n){
            ans = a[1];
            for(int i = 2; i <= n; i++) ans = ans & a[i];
        }
    }
    else if(m == n - 1){
        for(int i = 1; i <= n; i++){
            int num = a[i], cntt = 1;
            while(num){
                if(num & 1) b[cntt]++;
                num = num >> 1;
                cntt++;
            }
        }
        for(int i = 1; i <= 30; i++)
            if(b[i] >= m) ans = ans + (1 << (i - 1));
    }
    else if(!fl){
        for(int i = 1; i <= n; i++) t[a[i]]++;
        if(t[4] >= m) ans = 4;
        else if(t[3] >= m) ans = 3;
        else if(t[3] + t[2] >= m) ans = 2;
        else if(t[3] + t[1] >= m) ans = 1;
    }
    else{
        sort(a + 1, a + n + 1);
        ans = a[n - m + 1];
    }
    printf("%d", ans);
}
