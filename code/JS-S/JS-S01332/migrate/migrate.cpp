#include <bits/stdc++.h>
using namespace std;
int c,n,t;
struct node
{
    int sum,cnt;
}dis[2000005];
long long d,p,x[2000005],ans;
vector <int> s[2000005],ep;
void Dij(int st)
{
    for (int i = 1; i <= n; i++)
        dis[i] = {20000005,0};
    queue <int> q;
    q.push(st);
    dis[st] = {0,1};
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < s[p].size(); i++)
            if (dis[p].sum + 1 == dis[s[p][i]].sum)
                dis[s[p][i]].cnt += dis[p].cnt;
            else if (dis[p].sum + 1 < dis[s[p][i]].sum)
                dis[s[p][i]] = {dis[p].sum + 1,dis[p].cnt},
                q.push(s[p][i]);
    }
    for (int i = 1; i <= n; i++)
        if (dis[i].cnt == 2)
            ans++;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        ans = 0;
        scanf("%d%lld",&n,&d);
        for (int i = 1; i <= n; i++)
            scanf("%lld",&x[i]);
        if (c == 11 || c == 12)
        {
            p = d / (x[2] - x[1]);
            if (p == 0)
                puts("0");
            printf("%lld\n",n - (2 * p - 1));
        }
        else if (c == 13 || c == 14)
        {
            for (int i = 1; i < n; i++)
            {
                int idx = upper_bound(x + 1,x + n + 1,x[i] + d) - x - 1;
                if (idx < n)
                    ans += (upper_bound(x + 1,x + n + 1,x[idx - 1] + d) - x - 1 <= n);
            }
            printf("%lld\n",ans);
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                s[i] = ep;
                for (int j = i; j <= n; j++)
                    if (x[i] >= x[j] - d)
                        s[i].push_back(j);
            }
            for (int i = 1; i < n; i++)
                Dij(i);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
