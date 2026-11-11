#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int way,sz;
};

map<int,Node> f;
int x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        int n,d,cnt=0;
        cin >> n >> d;
        for (int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        for (int i=1;i<=n;i++)
        {
            f[x[i]]={1,0};
            for (auto &p:f)
            {
                if (p.first+d>=x[i])
                {
                    int t1=(p.second).way+1,t2=f[x[i]].way;
                    Node a={max(t1,t2),p.second.sz+1};
                }
            }
        }
        for (auto &p:f)
        {
            if (p.second.sz==2) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
