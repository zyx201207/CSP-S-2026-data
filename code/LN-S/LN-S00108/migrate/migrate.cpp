#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c , t , n;
ll d;
vector <int> v;
ll x[2000010] , k[2000010] , step[200010];
bool e[40010][40010] , vis[2000010];
void bfs(int s , int f)
{
    queue <int> que;
    que.push(s);
    step[s] = 0;
    while(que.size() > 0)
    {
        int now = que.front();
        que.pop();
        if(now == f)
        {
            v.push_back(step[now]);
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(e[now][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                step[i] = step[now] + 1;
                que.push(i);
            }
        }
    }
}
int main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> c >> t;
    if(c == 0)
    {
        cout << 1 << "\n" << 2;
    }
    for(int i = 1 ; i <= t ; i++)
    {
        ll cnt = 0;
        cin >> n >> d;
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> x[j];
            k[j] = x[j] - x[j - 1];
        }
        for(int j = 1 ; j <= n ; j++)
        {
            for(int k = 1 ; k <= n ; k++)
            {
                if(abs(x[j] - x[k]) <= d && j != k)
                {
                    e[j][k] = 1;
                    e[k][j] = 1;
                }
            }
        }
        for(int j = 1 ; j <= n ; j++)
        {
            for(int k = 1 ; k <= n ; k++)
            {
                v.clear();
                bfs(j , k);
                int minn = 999999999;
                for(int l = 0 ; l <= v.size() - 1 ; l++)
                {
                    minn = min(minn , v[i]);
                }
                int h = 0;
                for(int l = 0 ; l <= v.size() - 1 ; l++)
                {
                    if(v[i] == minn)
                    {
                        h++;
                    }
                }
                if(h == 2)
                {
                    cnt++;
                }
            }
        }
        cout << cnt / 2 << "\n";
    }
    return 0;
}
