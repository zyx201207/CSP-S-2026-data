#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t --){
        int n,d;
        scanf("%d%d",&n,&d);
        vector<int> a(n + 1);
        for (int i = 0;i < n;++ i){
            scanf("%d",&a[i]);
        }
        int ans = 0;
        for (int i = 0;i < n;++ i){
            for (int j = i + 3;j < n;++ j){
                queue<pair<int,int>> q;
                int cnt = 0,zd = INT_MAX;
                q.push({i,0});
                while (!q.empty()){
                    auto u = q.front();
                    q.pop();
                    if (u.first == j){
                        if (cnt == 0){
                            zd = u.second;
                        }
                        ++ cnt;
                    }
                    if (u.second > zd) continue;
                    if (cnt >= 2) break;
                    for (int x = 0;x < n;++ x){
                        if (x == u.first) continue;
                        if (x < i || x > j) continue;
                        if (abs(a[u.first] - a[x]) <= d){
                            q.push({x,u.second + 1});
                        }
                    }
                }
                if (cnt >= 2){
                    ++ ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
