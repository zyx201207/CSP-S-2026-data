#include <bits/stdc++.h>
using namespace std;
string g;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        char a;
        cin >> x >> a;
        for(int i = 1;i <= x;i++)
        {
            g.push_back(a);
        }
    }
    //for(int i = 0;i < g.size();i++)
    //{
        //cout << g[i];
    //}
    for(int i = ceil(g.size()*1.0/2);i <= g.size()-1;i++)
    {
        if(g[i] != g[g.size()-i-1])
        {
            g[i] = g[g.size()-i-1];
            ans++;
        }
    }
    cout << ans;
}
