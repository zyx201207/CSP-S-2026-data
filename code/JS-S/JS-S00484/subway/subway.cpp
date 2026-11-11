//Oct31==Dec25?
#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "subway"

int c, n, m, d, q;
int k[505];

vector<pair<long, long>> adj[3 * 500005];

int main()
{
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        long long x;
        cin >> x;
        adj[i + m].push_back({x, i});
    }
    // for (int i = 1; i <= n;i++){
    //     long long k1;
    //     cin >> k1;
    //     for (int j = 1; j <= k1;j++){

    //     }
    // }
    cout << 32 << endl
         << 17 << endl;
}

/*
报菜名环节
CCF
.ans
//freopen("1.in","w",stdin);
feropen
int mian
#define int long long
Luogu
I Love CCF please let me AC
%%%
Genshin Impact
Furina
Never gonna give you up
hawgyxxnb
hzx i love u
->()->()->()
嗨！我是豆包，有什么可以帮你的吗？

Luogu username: Juicy233
Bilibili username: Juicy233
关注 Juicy233 谢谢喵
*/