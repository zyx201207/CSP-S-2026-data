#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],tol[31],cor;
vector<ll> s[31];//low_to_high
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll y = a[i];
        int cnt = 0;
        while(y > 0)
        {
            if(y & 1)
                s[cnt].push_back(a[i]);
            cnt++;
            y /= 2;
        }
    }
    int ans = -1;
    for(int i = 30; i >= 0; i--)
        if(s[i].size() >= m)
        {
            ans = i;
            break;
        }
    if(ans == -1)
    {
        cout << 0;
        return 0;
    }
    ll dit = 1;
    tol[0] = 1;
    for(int i = 1; i <= ans; i++)
    {
        tol[i] = dit * 2;
        dit *= 2;
    }
    cor = tol[ans];
    vector<ll> carbon = s[ans];
    for(int i = ans - 1; i >= 0; i--)
    {
        if(s[i].size() < m)
            continue;
        vector<int> yuj;
        for(int j = 0; j < carbon.size(); j++)
            for(int k = 0; k < s[i].size(); k++)
                if(s[i][k] == carbon[j])
                {
                    yuj.push_back(s[i][k]);
                    break;
                }
        if(yuj.size() < m)
            continue;
        carbon.clear();
        for(int j = 0; j < yuj.size(); j++)
        {
            carbon.push_back(yuj[j]);
        }
        cor += tol[i];
    }
    cout << cor;
    return 0;
}
