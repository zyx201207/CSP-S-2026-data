#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 5,INF = 0x3f3f3f3f3f3f3f3f;
ll c,t,n,d,x[N],nxt[N],pre[N],opt[N][2],ans;
//0oddhere,1oddbeyond,2evenhere,3evenbeyond
int main() 
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while (t--) 
    {
        ans = 0;
        cin >> n >> d;
        for (ll i = 1; i <= n; i++) cin >> x[i];
        pre[1] = 1;
        for (ll i = 2; i <= n; i++) 
        {
            pre[i] = pre[i - 1];
            while (x[i] - x[pre[i]] > d) pre[i]++;
        }
        for (ll i = 1; i <= n; i++) 
        {
            for (ll j = i; j <= n; j++) opt[j][0] = opt[j][1] = 0;
            opt[i][1] = 1;
            for (ll j = i + 1; j <= n; j++) 
            {
                opt[j][0] = opt[max(i,pre[j])][0] + 1;
                for (ll k = max(i,pre[j]); k < j; k++) 
                    if (opt[k][0] + 1 <= opt[j][0]) 
                        opt[j][1] += opt[k][1];
                // cout << opt[j][1] << endl;
                if (opt[j][1] == 2) ans++;
            }
        }
        cout << ans << '\n';
        // nxt[n] = n;
        // for (ll i = n - 1; i; i--) 
        // {
        //     nxt[i] = nxt[i + 1];
        //     while (x[nxt[i]] - x[i] > d) nxt[i]--;
        // }
        // pre[1] = 1;
        // for (ll i = 2; i <= n; i++) 
        // {
        //     pre[i] = pre[i - 1];
        //     while (x[i] - x[pre[i]] > d) pre[i]++;
        // }
        // for (ll i = 1; i <= n; i++) 
        // {
        //     if (pre[i] != i) 
        //     {
        //         if (nxt[pre[i]] == i) 
        //         {
        //             opt[i][0] += opt[pre[i]][0] + 1;
        //             opt[i][1] += sum[i - 1] - sum[pre[i]] + i - pre[i] - 1;
        //             opt[i][2] += opt[pre[i]][2];
        //             if (pre[pre[i]] != pre[i] && nxt[pre[pre[i]]] > pre[i]) 
        //                 opt[i][2] += opt[pre[pre[i]]][0] + 1;
        //                 // opt[i][3] += 
        //         }
        //         else opt[i][1] += sum[i - 1] - sum[pre[i] - 1] + i - pre[i];
        //         if (pre[pre[i]] != pre[i]) 
        //         {
        //             if (nxt[pre[pre[i]]] == pre[i]) 
        //                 opt[i][2] += opt[pre[i]][2] + opt[pre[i]][3];
        //         }
        //     }
        //     // opt[i][0] += i - pre[i];
        //     // if (pre[i] != i && pre[pre[i]] != pre[i]) 
        //     // {
        //     //     if (nxt[pre[pre[i]]] == pre[i]) 
        //     //         opt[i][0] += opt[pre[pre[i]]][0] + 1,
        //     //         opt[i][1] += opt[pre[pre[i]]][1];
        //     //     else opt[i][1] += opt[pre[pre[i]]][0] + 1;
        //     // }
        //     // ans += opt[i][1];
        //     sum[i] = sum[i - 1] + opt[i][0];
        // }
        // cout << ans << endl;
    }
    return 0;
}
// i'm very angry /fn/fn/fn
// swc17 & q8m try to get lhp's accounts /fn/fn/fn
// /fn/fn/fn
