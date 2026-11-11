#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6+10;
int c,t,n,d,x[maxn],num,ans,dis;
int ver[maxn],head[maxn],nxt[maxn],cnt;
void add(int u,int v)
{
    ver[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
struct node
{
    int i,st;
};
signed main()
{
    //rp++ orz
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cout << 1;
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> x[i];
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                if(x[j]-x[i] <= d) add(i,j);
            }
        }
        for(int a = 1;a <= n;a++)
        {
            for(int b = a+3;b <= n;b++)
            {
                num = 0;
                queue<node> q;
                q.push({a,0});
                while(!q.empty())
                {
                    int u = q.front().i,step = q.front().st;
                    q.pop();
                    for(int i = head[u];i;i = nxt[i])
                    {
                        int v = ver[i];
                        q.push({v,step+1});
                        if(v == b)
                        {
                            num++;
                        }
                    }
                }
                if(num == 2)ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
