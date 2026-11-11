#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2000006;
const int INF = (1ll << 62) - 1;

int c,T;
int n,d;
int x[maxn];
int pos[maxn];
int ans;

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        ans = 0;
        cin>>n>>d;
        for(int i = 1;i <= n;i++) cin>>x[i];
        x[n + 1] = INF;
        int r = 1;
        for(int i = 1;i <= n;i++)
        {
            while(x[r + 1] <= x[i] + d) r++;
            pos[i] = r;
        }
        for(int i = 1;i <= n;i++)
        {
            int cur = pos[i];
            if(cur - i <= 1) continue;
            int cur_1 = cur - 1;
            int cur_2 = cur - 2;
            ans += pos[cur_1] - pos[cur_2];
        }
        cout<<ans<<"\n";
    }
}