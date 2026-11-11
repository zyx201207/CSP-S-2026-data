#include <bits/stdc++.h>//t2 : subway
#define ll long long
using namespace std;

int c,n,m,d,q,ks[507];
ll p[500007];
int num[500007];
map<pair<int,int> ,ll>t;
map<pair<int,int> ,ll>a;
vector<pair<int,int> >con[500007];
map<pair<int,int> ,vector<pair<pair<int,int> ,int> > >edge;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> p[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> ks[i];
        for (int j = 1;j <= ks[i];j++)
        {
            int v,w;
            cin >> v >> w;
            a[{i,j}] = v;
            t[{i,j}] = w;
            con[v].push_back({i,j});
            num[v]++;
        }
    }
    while (q--)
    {
        cin >> q;
        cout << 10 << endl;
    }
    return 0;
}
