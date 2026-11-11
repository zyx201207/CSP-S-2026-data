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
int t,n,c,m,a[2000005];
void solve()
{
    bool a_ok = true,b_ok = true,c_ok = true;
    n = read(),m = read();
    for(int i = 1;i<=n;i++)
    {
        a[i]=read();
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
            a_ok = false;
    }
    if(a_ok)
    {
        int d = a[2]-a[1];
        if(m<2*d)
        {
            cout << 0 << endl;
            return;
        }
        cout << max((int)0,n-2*(int)(m/d)+1) << endl;
        return;
    }
    cout << "no" << endl;
}

bool t1;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read(),t = read();
    while(t--)
    {
        solve();
    }
    cerr << " " << (&t1-&s1)/1024.0/1024.0 << "MB" << endl;
}
