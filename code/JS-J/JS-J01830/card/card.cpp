#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e5 + 5, M = 3e5 + 5;

queue<int> t[M];
queue<int> td[M]

int d[N], a[N], s[N];
int mem[M];
int cnt[M];


int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("card.in", "r", stdin);
//    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        t[a[i]].push(i);
    }

    for (int i = 1; i <= n; i++){
        d[i]++;
        auto& q = t[a[i]];
        if (!q.empty()){
            mem[a[i]]++;
            d[q.back()]++;
            d[i]--;
            for (int i = 1; i <= n; i++){

            }
        }
        s[i] = s[i-1] + d[i];
        q.pop();
    }

    for (int i = 1; i <= n; i++){
        cnt[a[i]] += s[i];
    }

    for (int i = 1; i <= m; i++){
        cout << cnt[i] << " ";
    }

    return 0;
}
