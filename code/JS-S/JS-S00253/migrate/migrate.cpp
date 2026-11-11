#include <bits/stdc++.h>
using namespace std;

long long c,t;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t--)
    {
        long long n,d,x,cha,ans=0;
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        if(n==1)
        {
            cout << 0 << endl;
            continue;
        }
        cha=a[2]-a[1];
        d=d/cha;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((j-i)<=d)
                    continue;
                if((j-i)%d!=0)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
