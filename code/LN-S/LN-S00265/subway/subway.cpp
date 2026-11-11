#include <bits/stdc++.h>
using namespace std;

int vz[500005];
int p[1005][1005];
int jl[305][1005];
int e[305][1005];
int jg[1005][24];
bool pd[500005];
int tot[1005];
int how[305];
void add(int x,int y,int v)
{
            // cout <<"nihao"<<x<<y<<v << endl;
    p[x][y] = v;
    p[y][x] = v;
}
int main()
{
    for(int i = 1;i<=1004;i++)
    {
        for(int j = 1;j<=1004;j++)
        {
            p[i][j] = 0x3f3f3f;
        }
    }
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    /*vector<int> vz(m);
    vector<vector<int>> p(m);
    vector<pair<int,int>> jl(n);
    vector<vector<int>> e(n);
    vector<vector<int>>jg(d);*/
    cin >> c >>n>>m>>d>>q;
    for(int i =1;i<=m;i++)
        {
            cin >> vz[i];
        }
    for(int i =1;i<=n;i++)
    {
        int k;
        cin >>k;
        how[i] = k;
        for(int j = 1;j<=k;j++)
        {
            int a,b;
            cin >> a>>b;
            jl[i][j] =a;
            e[i][a] = b;
            pd[j] = 1;
            jg[j][++tot[j]] = i;
        }
    }
    for(int i =1;i<=n;i++)
    {
         //cout <<"nihao" << endl;
        for(int j =1;j <= how[i];j++)
        {
            auto z= jl[i][j];
            //cout <<"z: " <<z<<endl;
            for(int nihao =1;nihao<=m;nihao++)
            {
            auto z2 = jl[i][nihao];
                add(z,z2,0);
            }
            for(int ii =1;ii<=d;ii++)
            {
                int jj = jg[z][ii];
                int t = e[i][z] + e[jj][z];
                for(int zz=1;zz<=how[jj];zz++)
                {
                    int z2 = jl[jj][zz];
                    if(t<p[z][z2])
                    {
                        add(z,z2,t);
                    }
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x>>y;
        long long ans = 0;
        ans += vz[x];
        ans+=vz[y];
        ans+=p[x][y];
       //cout <<p[x][y] << endl;
        cout << ans << endl;
    }
    return 0;
}
