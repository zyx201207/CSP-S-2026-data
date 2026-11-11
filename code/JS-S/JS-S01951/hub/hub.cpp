#include<iostream>
#include<queue>
#include<vector>
#define AK return
#define CSP 0;
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<vector<int>> g(n+1);
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int r = 1e9;
        for(int i = 0;i < (1 << n);i++)
        {
            if(__builtin_popcount(i) != k)
            {
                continue;
            }
            int c = 0,cc = 0;
            vector<bool> b(n+1,false);
            queue<int> qq;
            while(cc < k)
            {
                for(int j = 1;j <= n;j++)
                {
                    if((i & (1 << (j-1))) && !b[j])
                    {
                        c++;
                        cc++;
                        b[j] = true;
                        qq.push(j);
                        break;
                    }
                }
                while(!qq.empty())
                {
                    int u = qq.front();
                    qq.pop();
                    for(auto j : g[u])
                    {
                        if((i & (1 << (j-1))) && !b[j])
                        {
                            b[j] = true;
                            qq.push(j);
                            cc++;
                        }
                    }
                }
            }
            if(c > 2)
            {
                continue;
            }
            queue<int> q;
            vector<int> d(n+1,1e9);
            vector<bool> v(n+1,false);
            for(int j = 1;j <= n;j++)
            {
                if(i & (1 << (j-1)))
                {
                    //cout << j << ' ';
                    d[j] = 0;
                    q.push(j);
                    v[j] = true;
                }
            }
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(auto &i : g[u])
                {
                    if(!v[i])
                    {
                        v[i] = true;
                        d[i] = d[u]+1;
                        q.push(i);
                    }
                }
            }
            int rr = 0;
            for(int j = 1;j <= n;j++)
            {
                if(d[j] != 1e9)
                    rr = max(rr,d[j]);
            }
            //cout << rr << '\n';
            r = min(r,rr);
        }
        cout << r << '\n';
    }
    AK CSP
}
