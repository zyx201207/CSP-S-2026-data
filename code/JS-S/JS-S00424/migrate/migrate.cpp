#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
signed main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        int ans=0;
        for (int i=1;i<=n;i++) cin >> x[i];
        for (int i=1;i<=n-3;i++)
        {
            for (int j=i+3;j<=n;j++)
            {
                int tmp=x[j+1];
                x[j+1]=(1ll<<62ll);
                int k=i,f=0,p1=i;
                while (x[k]-x[i]<=d) ++k;
                if (k==i+1) continue;
                p1=k-1;
                while (k<=j+1)
                {
                    if (x[k]-x[p1]>d)
                    {
                        if (k==p1+1) {f=0;break;}
                        if (x[k-1]-x[p1-1]<=d) ++f;
                        if (f==2) {break;}
                        p1=k-1;

                    }
                    ++k;
                }
                if (f==1) ++ans;
                x[j+1]=tmp;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
