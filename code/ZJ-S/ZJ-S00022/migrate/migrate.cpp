#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+10;
int n, len[MAXN], cnt[MAXN], ans;
long long x[MAXN], d;

void bfs(int s){
    memset(len, 0x3f, sizeof(len));
    memset(cnt, 0, sizeof(cnt));
    queue <pair<int, int> > q;
    q.push({0, s});
    while (!q.empty()){
        int w = q.front().first, u = q.front().second;
        q.pop();
        if (u > n){
            continue;
        }
        if (len[u] == w){
            cnt[u]++;
        } else if (len[u] > w) {
            len[u] = w;
            cnt[u] = 0;
        } else {
            continue;
        }
        int i = 1;
        while (u+i <= n && x[u+i]-x[u] <= d){
            q.push({w+1, u+i});
            i++;
        }
    }
}

void read(int &val){
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
    val = sum*sign;
}

void read(long long &val){
    long long sum = 0, sign = 1;
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
    val = sum*sign;
}

int main(){ freopen("migrate.in", "r", stdin);
            freopen("migrate.out", "w", stdout);
            int _, T; read(_); read(T); while(T--)
{
    ans = 0;
    read(n);
    read(d);
    for (int i = 1; i <= n; i++){
        read(x[i]);
    }
    for (int u = 1; u <= n; u++){
        bfs(u);
        for (int v = 1; v <= n; v++){
            if (cnt[v] == 1){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}}
