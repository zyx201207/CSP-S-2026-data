#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,c,t,d,a[2000005],ans = 0;
int dist[5005][5005];
struct node
{
    ll u,w;
};
bool cmp(node X,node Y)
{
    if(X.u == Y.u)
    {
        return X.w < Y.w;
    }
    return X.u < Y.u;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        memset(dist,0x3f,sizeof(dist));
        vector<node>t[5005];
        cin >> n >> d;
        for(int i =1; i<=n; i++)
        {
            cin >> a[i];
            t[i].push_back({i,0});
        }
        for(int i = 1; i<n; i++)
        {
            for(int j = i + 1; j<=n; j++)
            {
                if(a[j] - a[i] <= d)
                {
                    for(auto v:t[i])
                    {
                        if(dist[v.u][j] >= v.w + 1)
                        {
                            t[j].push_back({v.u,v.w + 1});
                            dist[v.u][j] = v.w + 1;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for(int i =1; i<=n; i++)
        {
            if(t[i].size() < 2) continue;
            sort(t[i].begin(),t[i].end(),cmp);
            int cnt = 0,mi = -1,id = 0;
            for(auto v:t[i])
            {
                if(v.u != id)
                {
                    if(cnt == 2) ans++;
                    cnt = 0,mi = -1;
                    id = v.u;
                }
                if(mi == -1)
                {
                    mi = v.w;
                    cnt++;
                }
                else if(mi == v.w)
                {
                    cnt++;
                }
            }
        }
        cout << ans << "\n";
    }
}
