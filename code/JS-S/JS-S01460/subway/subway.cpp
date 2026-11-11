#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long c,n,m,d,q,w[500005],k,a,t,f[500505];
bool flag[500505];
struct T
{
    long long dis,ti;
};
vector <T> ve[500505];
void Dijsktra(long long r)
{
    flag[r] = true;
    for (int j = 0;j < ve[r].size();j++)
    {
        if (flag[ve[r][j].dis])
            continue;
        if (f[ve[r][j].dis] == 0x3f3f3f3f || f[r] + ve[r][j].ti < f[ve[r][j].dis])
            f[ve[r][j].dis] = f[r] + ve[r][j].ti;
        Dijsktra(ve[r][j].dis);
    }
    flag[r] = false;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (long long i = 1;i <= m;i++)
        cin >> w[i];
    for (long long i = 1;i <= n;i++)
    {
        cin >> k;
        for (long long j = 1;j <= k;j++)
        {
            cin >> a >> t;
            ve[a].push_back({m + i,t});
            ve[m + i].push_back({a,t});
        }
    }
    while (q--)
    {
        long long x,y;
        cin >> x >> y;
        memset(flag,0,sizeof(flag));
        memset(f,0x3f3f3f3f,sizeof(f));
        f[x] = 0;
        Dijsktra(x);
        cout << f[y] + w[x] + w[y] << endl;
    }
    return 0;
}
