#include<bits/stdc++.h>
#define int long long
using namespace std;
bool s1;
inline int read()
{
    int s = 0,w = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch == '-')
        {
            w *= -1;
        }
        ch = getchar();
    }
    while(!(ch<'0'||ch>'9'))
    {
        s = (s<<1)+(s<<3)+(ch^48);
        ch = getchar();
    }
    return s*w;
}
int c,n,m,d,q,w[500005],a[505][505],t[505][5005],f[305][305],k[505],changecost[305][305],changepoint[305][305];
vector<int>g[500005];
bool a_ok = true,b_ok = true;
bool t1;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i = 1;i<=m;i++)
        {
            w[i]=read();
        }
    for(int i = 1;i<=n;i++)
        {
            k[i] = read();
            if(k[i]>2)
            {
                a_ok = false;
            }
            for(int j = 1;j<=k[i];j++)
            {
                a[i][j]=read();
                t[i][j]=read();
            }
        }
    if(n<=50)
    {
        for(int i = 1;i<=m;i++)
        {
            w[i]=read();
        }
        for(int i = 1;i<=n;i++)
        {
            k[i] = read();
            for(int j = 1;j<=k[i];j++)
            {
                a[i][j]=read();
                t[i][j]=read();
            }
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=k[i];j++)
            {
                for(int h = 1;h<=k[i];h++)
                {
                    if(j == h)
                    {
                        f[a[i][j]][a[i][h]]=0;
                    }
                    else
                    {
                        f[a[i][j]][a[i][h]]=t[i][j]+t[i][h];
                    }
                }
            }
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=k[i];j++)
            {
                for(int h = 1;h<=n;h++)
                {
                    for(int l = 1;l<=k[h];l++)
                    {
                        if(i!=h&&a[i][j]==a[h][l])
                        {
                            changecost[i][h]=t[i][j]+t[h][l];
                            changepoint[i][h]=a[i][j];
                        }
                    }
                }
            }
        }
        int s, t;
        for(int i = 1;i<=q;i++)
        {
            s = read(),t = read();
            cout << s+t << endl;
        }
    }
    return 0;
}
