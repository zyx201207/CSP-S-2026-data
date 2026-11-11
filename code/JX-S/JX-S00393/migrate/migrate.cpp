#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[100005];ll n,d;
int vis[100005];
int check(ll s,ll e)
{
    memset(vis,0x3f,sizeof(vis));
    queue<int>q;
    q.push(s);
    int minn = (1<<30);
    int cnt = 0;
    vis[s] = 0;
    while(!q.empty())
    {
        int i = q.front();
       // cout << i  << " " << vis[i] << endl;
        q.pop();
        int j = i;
        if(i == e)
        {
            if(vis[i]<=minn)
            {
                cnt++;
                minn = vis[i];
                if(cnt >= 3)return 3;
            }
            else
            {
                return cnt;
            }
            continue;
        }
        for(int j = i+1;j<=n;j++)
        {
            if((x[j] <= x[i]+d) && (vis[j]>=vis[i]+1))
            {
            //    cout << j << endl;
                vis[j] = vis[i]+1;
                q.push(j);
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T,c;
    cin  >> c >> T;
    while(T--)
    {
        cin >> n >> d;
        for(int i = 1;i<=n;i++)
        {
            cin >> x[i];
        }
        int cnt = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = i+1;j<=n;j++)
            {
                if(check(i,j) == 2)cnt++;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}
