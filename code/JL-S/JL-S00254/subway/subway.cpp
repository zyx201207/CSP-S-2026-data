#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[(int)1e6];
struct pnt{
    long long t,num;
}a[(int)1e6],b[(int)1e6];
long long k,a1,t1,a2,t2,x,y,x1,x2;
long long ans,ans1,ans2;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> k;
        cin >> a1 >> t1 >> a2 >> t2;
        a[a1].t=a2;
        a[a1].num=t1+t2;
        b[a2].t=a1;
        b[a2].num=t1+t2;
    }
    for (int i=1;i<=q;i++)
    {
        cin >> x >> y;
        ans=0;
        ans1=0;
        ans2=0;
        ans+=w[x]+w[y];
        x1=x;
        x2=x;
        while (x1!=0||x2!=0)
        {
            ans1+=a[x1].num;
            x1=a[x1].t;
            ans2+=b[x2].num;
            x2=b[x2].t;
            if (x1==y)
            {
                ans+=ans1;
                break;
            }
            if (x2==y)
            {
                ans+=ans2;
                break;
            }
        }
        cout << ans << endl;
    }
}
