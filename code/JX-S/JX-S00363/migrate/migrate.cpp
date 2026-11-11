#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005], na[2000005], lu[2000005], vis[2000005];
int p[2000005], q[2000005], q1[2000005], q0[2000005];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i], na[i] = i, vis[i] = q[i]=q0[i]=q1[i]=0;
        int ans = 0, pp = 1;
        for (int i = 1; i <= n; i++) {
            while (pp + 1 <= n && a[pp + 1] - a[i] <= d)
                pp++;
            na[i] = pp;
        }
        for (int i = 1; i <= n; i++) {
            int x = i, tot = 0;
            p[0] = i;
            while (x != na[x])
                p[++tot] = na[x], x = na[x];
            int ling=0,yi=0;
            for (int j = 1; j < tot; j++) {
                int z = 0, x = p[j];
                if (x - 1 > p[j - 1] && na[x - 1] >= p[j + 1])
                    z++;
                if (x - 2 > p[j - 1] && na[x - 2] >= p[j + 1])
                    z++;
                q[j] = q[j - 1] + z;
                q1[j] = q1[j - 1];
                q0[j] = q0[j - 1];
                int ll = p[j] + 1, rr = p[j + 1];
                if (p[j] - 2 > p[j - 1])
                    ll = max(ll, na[p[j] - 2] + 1);
                if (p[j] - 1 > p[j - 1]) {
                    rr = min(rr, na[p[j] - 1]);
                    int u = max(0LL, rr - ll + 1);
                    q1[j] += u;
                }
                ll = p[j] + 1, rr = p[j + 1];
                if (p[j] - 2 > p[j - 1])
                    ll = max(ll, na[p[j] - 2] + 1);
                if (p[j] - 1 > p[j - 1])
                    ll = max(ll, na[p[j] - 1] + 1);
                int u = max(0LL, rr - ll + 1);
                q0[j] += u;
                //cout << j << " " << q[j]<<" "<<q1[j]<<" "<<q0[j]<<" "<<ans<<endl;
            }
            while(ling+1<=tot-2&&q[ling+1]==0)ling++;
            while(yi+1<=tot-2&&q[yi+1]<=1)yi++;
            for(int k=tot-1;k>=1;k--)
                    if(q[k-1]==0)
                        ans+=q1[k]-q1[k-1];
                for(int k=tot-1;k>=1;k--)
                    if(q[k-1]==1)
                    ans+=q0[k]-q0[k-1];
        }
        cout << ans << "\n";
    }
    return 0;
}


