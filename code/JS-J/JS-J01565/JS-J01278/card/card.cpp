#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pong;
int n,m;
int a[500005],b[300005];
vector<int> pos[300005];
stack<int> tmp;
pong h[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        h[i].first = pos[a[i]].size();
        h[i].second = a[i];
        pos[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(pos[a[j]][h[j].first - 1] >= i)
                while(tmp.top() != a[j])
                    tmp.pop();
            tmp.push(a[j]);
        }
        for(int j = 0; j < tmp.size(); j++)
        {
            b[tmp.top()]++;
            tmp.pop();
        }
    }
    for(int i = 1; i <= m; i++)
        cout << b[i] << ' ';
    return 0;
}
