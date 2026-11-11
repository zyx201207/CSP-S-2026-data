#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n;
ll x[2000005],d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%lld",&n,&d);
        for (int i = 1;i <= n; i++)
            scanf("%lld",x + i);
        int ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = i + 1;j <= n; j++)
            {
                queue<pair<int,int>>q;
                q.push({i,0});
                int M,cnt;
                M = 1e9,cnt = 0;
                while(q.size())
                {
                    auto t = q.front();
                    q.pop();
                    if (t.first == j)
                    {
                        if (t.second < M)
                            M = t.second,cnt = 1;
                        else if (t.second == M)
                            cnt++;
                    }
                    for (int k = t.first + 1;k <= j; k++)
                        if (x[k] - x[t.first] <= d)
                            q.push({k,t.second + 1});
                }
                ans += (cnt == 2);
            }
        printf("%d\n",ans);
    }
    return 0;
}
/*
0000001111111 2
        1111111 2
        001111111 1
        0001111111 1
        00001111111 1
        000000001111111 0

*/
